typedef struct Location {
    int x, y;
} Location;
Location hs2[105][105];

typedef struct InterVal { // 数独每行每列可能选取的选填区间
    int l, r;
} InterVal;
InterVal intervals[1005];
int intervals_index;

// 子句的头结点定义
typedef struct ClauseHead {
    int size; // 子句的变量个数
    struct ClauseHead* next; // 连接到下一个子句
    struct VarNode* var_list; // 子句里面的变量
} ClauseHead;

// ClauseHead* recycle_bin[100005]; // 存储DPLL过程中删掉的子句
// int recycle_bin_index;
int free_VarNode_in_ClauseHead(ClauseHead** node);

// 子句的变量结点
typedef struct VarNode {
    int value;
    struct VarNode* next;
} VarNode;

int VarNode_init(VarNode** node) {
    // debug("enter VarNode_init\n");
    // 创建新的结点并且初始化, 然后插入到当前链表尾端, 并且返回尾端结点以便于操作
    assert(!(*node));
    // if (*node) { // 已经被初始化
    //     printf("VarNode_init: 0\n"); // 理论上程序中不应该返回0
    //     return 0;
    // }
    *node = (VarNode*) malloc(sizeof(VarNode));
    (*node)->next = NULL;
    (*node)->value = 0;
    // debug("VarNode_init: 1\n");
    return 1;
}
    
int VarNode_length(VarNode* node) {
    int length = 0;
    VarNode* p = node;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

int VarNode_print(VarNode* node) {
    debug("enter VarNode_print\n");
    if (node == NULL) {
        debug("node is empty!\n");
        debug("VarNode_print: 0\n");
        return 0;
    }
    VarNode* p = node;
    while (p) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
    debug("VarNode_print: 1\n");
    return 1;
}

int VarNode_find(VarNode* node, int value) { // 查找变量链表中是否含有value这个变量
    // debug("enter VarNode_find\n");
    VarNode* p = node;
    while (p) {
        if (p->value == value) {
            // debug("VarNode_find: 1\n");
            return 1; // 找到
        }
        p = p->next;
    }
    // debug("VarNode_find: 0\n");
    return 0; // 找不到
}

int VarNode_push(VarNode** head, VarNode* node) { // 插入新的VarNode带链表尾端
    // debug("enter VarNode_push\n");
    if (*head == NULL) {
        *head = node;
        // debug("VarNode_push: 1\n");
        return 1;
    }
    VarNode* p = *head;
    while (p->next) {
        p = p->next;
    }
    p->next = node;
    // debug("VarNode_push: 1\n");
    return 1;
}

int VarNode_delete(VarNode** node, int value) { // 删掉变量值为value的结点
    debug("enter VarNode_delete\n");
    VarNode* p = (*node);
    int cnt = 0; // 记录一下删除了多少个结点
    // value可能不止一个, 所以需要while循环删除
    assert(*node);
    while (p) {
        if (p->value == value) {
            *node = (*node)->next;
            // VarNode_print(*node);
            debug("deleted1, p->value: %d\n", p->value);
            // VarNode_print(*node);
            free(p);
            // p = NULL;
            cnt++;
            p = *node; // 指向新的头结点
        } else {
            break; // 第一个不需要删除了, 退出循环
        }
    }
    if (!(*node)) { // 删完了, 头结点为空, 不需要再删
        debug("\n");
        debug("VarNode_delete: %d\n", cnt);
        return cnt;
    }
    // 删除的是中间的结点
    p = (*node)->next;
    VarNode* pre = (*node);
    while (p) {
        VarNode* nex = p->next;
        if (p->value == value) {
            // VarNode_print(*node);
            debug("deleted2, p->value: %d\n", p->value);
            pre->next = nex;
            // VarNode_print(*node);
            free(p);
            cnt++;
            p = nex;
            continue; // pre不需要改变
        }
        pre = p;
        p = nex;
    }
    // debug("\n");
    debug("VarNode_delete: %d\n", cnt);
    return cnt;
}

int ClauseHead_init(ClauseHead** node) {
    // debug("enter ClauseHead_init\n");
    assert(!(*node)); // 保证结点为空
    // if (*node) { // 结点不为空
    //     debug("ClauseHead_init: 0\n");
    //     return 0;
    // }
    *node = (ClauseHead*) malloc(sizeof(ClauseHead));
    (*node)->var_list = NULL;
    (*node)->next = NULL;
    (*node)->size = 0; // 子句变量数初始化为0
    // debug("ClauseHead_init: 1\n");
    return 1;
}

int ClauseHead_push(ClauseHead** list, ClauseHead* node) {
    // 不带头结点的链表, 所以第一个结点可能为空, 否则找到最后一个结点, 插入新节点到尾部
    // debug("enter ClauseHead_push\n");
    if (*list == NULL) {
        (*list) = node;
        debug("ClauseHead_push: 1\n");
        return 1;
    }
    ClauseHead* p = (*list);
    while (p->next) {
        p = p->next;
    }
    p->next = node;
    // debug("ClauseHead_push: 1\n");
    return 1;
}

int ClauseHead_delete(ClauseHead** node, int value) { // 删除子句含有value这个变量的子句
    debug("enter ClauseHead_delete\n");
    ClauseHead* p = *node;
    // 删掉第一个结点的情况
    while (p) { // 可能需要不断地删除第一个结点, 所以使用while
        int need_to_delete = VarNode_find(p->var_list, value);
        if (!need_to_delete) {
            break;
        } else {
            ClauseHead* pre_head = (*node); // 记录当前头结点
            *node = (*node)->next;
            p = *node; // 当前指针指向新的头结点
            free_VarNode_in_ClauseHead(&pre_head); // 先把子句里的所有变量结点free掉
            free(pre_head);
            pre_head = NULL;
            // recycle_bin[++recycle_bin_index] = pre_head;
        }
    }
    // 是否被删完了
    if ((*node) == NULL) {
        debug("ClauseHead_delete: 1\n");
        return 1;
    }
    // 删除中间的结点的情况
    ClauseHead* pre = (*node); // 创建前驱结点以便于删除当前结点
    ClauseHead* cur = (*node)->next;
    while (cur) {
        int need_to_delete = VarNode_find(cur->var_list, value); // 是否需要删除
        if (!need_to_delete) {
            pre = cur;
            cur = cur->next;
            continue;
        }
        ClauseHead* nex = cur->next;
        pre->next = nex;
        free_VarNode_in_ClauseHead(&cur);
        free(cur);
        cur = NULL;
        // recycle_bin[++recycle_bin_index] = cur;
        cur = nex; // 不需要指向NULL了, 直接指向下一个结点
    }
    debug("ClauseHead_delete: 1\n");
    return 1;
}

ClauseHead* ClauseHead_copy(ClauseHead* node) { // 拷贝一份新的子句集
    // debug("enter ClauseHead_copy\n");
    ClauseHead* new_node = NULL;
    ClauseHead* cur_node = node;
    while (cur_node) {
        ClauseHead* new_ClauseHead_node = NULL;
        ClauseHead_init(&new_ClauseHead_node);
        new_ClauseHead_node->size = cur_node->size;
        VarNode* pp = cur_node->var_list;
        while (pp) {
            VarNode* new_VarNode = NULL;
            VarNode_init(&new_VarNode);
            new_VarNode->value = pp->value;
            VarNode_push(&(new_ClauseHead_node->var_list), new_VarNode);
            // new_ClauseHead_node->size++; // 每push一个新的VarNode, ClauseHead的size就会增加1 // 没有必要这句话
            pp = pp->next;
        }
        ClauseHead_push(&new_node, new_ClauseHead_node);
        cur_node = cur_node->next;
    }
    // debug("ClauseHead_copy: 1\n");
    return new_node;
}

// ClauseHead* ClauseHead_init(ClauseHead** node) { // 创建新的子句结点并初始化, 插入到链表末端
//     ClauseHead* new_ClauseHead = (ClauseHead*) malloc(sizeof(ClauseHead));
//     ClauseHead* p = *node;
//     new_ClauseHead->next = NULL;
//     new_ClauseHead->var_list = NULL;
//     new_ClauseHead->size = -1; // 子句变元数初始化为-1
//     if (*node == NULL) { // 不带头节点
//         *node = new_ClauseHead;
//         return new_ClauseHead;
//     }
//     while (p->next) {
//         p = p->next;
//     }
//     p->next = new_ClauseHead;
//     return new_ClauseHead; // 返回当前插入的最新结点
// }

ClauseHead* isUnitClause(ClauseHead* node) { // 判断是否单子句
    // debug("enter isUnitClause\n");
    ClauseHead* p = node;
    while (p) {
        if (p->size == 1) {
            debug("isUnitClause: finded\n");
            return p;
        }
        p = p->next;
    }
    // debug("isUnitClause: NULL\n");
    return NULL; // 找不到单子句
}

int free_VarNode_in_ClauseHead(ClauseHead** node) { // 将子句中的每一个变量释放
    // debug("enter free_VarNode_in_ClauseHead\n");
    VarNode* p = (*node)->var_list;
    while (p) {
        VarNode* nex = p->next;
        free(p);
        p = nex;
    }
    // debug("free_VarNode_in_ClauseHead: 1\n");
    return 1;
}

int print_CNF(ClauseHead* head) {
    ClauseHead* p = head;
    while (p) {
        debug("size: %d\n", p->size);
        VarNode* pp = p->var_list;
        while (pp) {
            debug("pp->value: %d ", pp->value);
            pp = pp->next;
        }
        debug("\n");
        p = p->next;
    }
    // debug("printf_CNF: 1\n");
    return 1;
}