#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#ifdef LOCAL
#define debug printf
#else
#define debug(...) 114514
#endif

// 编码方式ijn -> i * 100 + j * 10 + n, 1代表true, -1代表false
// ijn表示f[i][j]填入n, -ijn表示f[i][j]不填入n
int bool_value[1005]; // 记录变量正负值
int frequency[1005]; // 记录变量(不包含负值)出现频次, 所以其实是正负值频次之和
int possitive_frequency[1005]; // 正值变量频次
int negative_frequency[1005]; // 负值变量频次

// 子句的头结点定义
typedef struct ClauseHead {
    int size; // 子句的变量个数
    struct ClauseHead* next; // 连接到下一个子句
    struct VarNode* var_list; // 子句里面的变量
} ClauseHead;

int free_VarNode_in_ClauseHead(ClauseHead** node);


// 子句的变量结点
typedef struct VarNode {
    int value;
    struct VarNode* next;
} VarNode;

int VarNode_init(VarNode** node) {
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

int VarNode_find(VarNode* node, int value) { // 查找变量链表中是否含有value这个变量
    VarNode* p = node;
    while (p) {
        if (p->value == value) {
            // printf("VarNode_find: 1\n");
            return 1; // 找到
        }
        p = p->next;
    }
    // debug("VarNode_find: 0\n");
    return 0; // 找不到
}

int VarNode_push(VarNode** head, VarNode* node) { // 插入新的VarNode带链表尾端
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
    VarNode* p = (*node);
    int cnt = 0; // 记录一下删除了多少个结点
    // value可能不止一个, 所以需要while循环删除
    while (p) {
        if (p->value == value) {
            *node = (*node)->next;
            free(p);
            cnt++;
            p = *node; // 指向新的头结点
        } else {
            break; // 第一个不需要删除了, 退出循环
        }
    }
    if (!(*node)) { // 删完了, 头结点为空, 不需要再删
        return cnt;
    }
    // 删除的是中间的结点
    p = (*node)->next;
    VarNode* pre = (*node);
    while (p) {
        VarNode* nex = p->next;
        if (p->value == value) {
            VarNode* nex = p->next;
            pre->next = nex;
            free(p);
            cnt++;
        }
        p = nex;
    }
    // debug("VarNode_delete: %d\n", cnt);
    return cnt;
}

int ClauseHead_init(ClauseHead** node) {
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
    if (*list == NULL) {
        (*list) = node;
        // debug("ClauseHead_push: 1\n");
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
        }
    }
    // 是否被删完了
    if ((*node) == NULL) {
        // debug("ClauseHead_delete: 1\n");
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
        cur = nex; // 不需要指向NULL了, 直接指向下一个结点
    }
    // debug("ClauseHead_delete: 1\n");
    return 1;
}

ClauseHead* ClauseHead_copy(ClauseHead* node) {
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
            VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
            // new_ClauseHead_node->size++; // 每push一个新的VarNode, ClauseHead的size就会增加1 // 没有必要这句话
            pp = pp->next;
        }
        ClauseHead_push(&new_node, new_ClauseHead_node);
        cur_node = cur_node->next;
    }
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

ClauseHead* isUnitClause(ClauseHead* node) {
    ClauseHead* p = node;
    while (p) {
        if (p->size == 1) {
            return p;
        }
        p = p->next;
    }
    return NULL; // 找不到单子句
}

int free_VarNode_in_ClauseHead(ClauseHead** node) {
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
            debug("%d ", pp->value);
            pp = pp->next;
        }
        debug("\n");
        p = p->next;
    }
    // debug("printf_CNF: 1\n");
    return 1;
}

int simplification(ClauseHead** head, int unit_value) {
    // 因为如果存在单子句, 则单子句里面的唯一变量必然为true, 所以整个子句可以删掉
    ClauseHead_delete(head, unit_value);
    // -unit必然为false, 所以删掉所有子句里面的-unit变量
    ClauseHead* p = (*head);
    while (p) {
        if (VarNode_find(p->var_list, -unit_value)) {
            int cnt = VarNode_delete(&(p->var_list), -unit_value);
            p->size -= cnt; // 减去删除掉的结点个数
            debug("%d\n", cnt);
        }
        p = p->next;
    }
    // debug("simplification: 1\n");
    return 1;
}

int existEmptyClause(ClauseHead* node) { // 查找是否存在空子句
    // 看子句的size是否为0
    ClauseHead* p = node;
    while (p) {
        if (p->size == 0) {
            debug("existEmptyClause: 1\n");
            return 1;
        }
        p = p->next;
    }
    // debug("existEmptyClause: 0\n");
    return 0;
}

// 选择出现频次最多的变量来赋值, 这样也许能够使子句集的长度缩小速度快一点
// 然后再根据正值和负值的出现频次, 选择频次较高的作为优化
int choose_unit_value(ClauseHead* node) {
    int max_frequency = 0, most_frequent_value = 0;
    ClauseHead* p = node;
    while (p) {
        VarNode* pp = p->var_list;
        while (pp) {
            if (frequency[abs(pp->value)] > max_frequency) { // 注意这里frequency统计的是正值
                max_frequency = frequency[pp->value];
                most_frequent_value = abs(pp->value);
            }
            pp = pp->next;
        }
        p = p->next;
    }
    if (possitive_frequency[most_frequent_value] > negative_frequency[most_frequent_value]) {
        debug("choose_unit_value: %d\n", most_frequent_value);
        return most_frequent_value;
    } else {
        debug("choose_unit_value: %d\n", -most_frequent_value);
        return -most_frequent_value;
    }
}

int add_unit_as_clause(ClauseHead** head, int unit_value) {
    ClauseHead* new_ClauseHead_node = NULL;
    ClauseHead_init(&new_ClauseHead_node);
    new_ClauseHead_node->size = 1;
    VarNode* new_VarNode = NULL;
    VarNode_init(&new_VarNode);
    new_VarNode->value = unit_value;
    VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
    ClauseHead_push(head, new_ClauseHead_node);
    debug("add_unit_as_clause: 1\n");
    return 1;
}

int DPLLsolve(ClauseHead** node) {
    ClauseHead* p = NULL;
    int unit_value = 0;
    // debug("*node: ");
    // print_CNF(*node);
    while ((p = isUnitClause(*node)) != NULL) { // 当子句集中存在单子句的时候
        // print_CNF(*node);
        unit_value = p->var_list->value; // var_list也就一个结点
        bool_value[abs(unit_value)] = unit_value > 0 ? 1 : -1;
        simplification(node, unit_value);
        if (*node == NULL) {
            debug("DPLLsolve: 1\n");
            return 1; // 说明所有条件都已满足
        } else if (existEmptyClause(*node)) { // 如果存在空子句, 那么这个空子句的值再不可能为true, 所以无解
            debug("DPLLsolve: 0\n");
            return 0;
        }
    }
    unit_value = choose_unit_value(*node);
    bool_value[abs(unit_value)] = unit_value > 0 ? 1 : -1; // 第一个赋值选择, 正值为true, 赋值为false
                                                            // 关键是正值为true的时候, 就已经可以知道这一个格子填什么数字, 所以先走这一条路
    ClauseHead* original_copy1 = ClauseHead_copy(*node);
    // debug("original_copy1:\n");
    // print_CNF(original_copy1);
    add_unit_as_clause(&original_copy1, unit_value); // 将变量作为单子句加入子句集中, 然后递归地解决这个问题
    // debug("original_copy1(after adding unite_clause): \n");
    // print_CNF(original_copy1);
    if (DPLLsolve(&original_copy1)) {
        debug("DPLLsolve: 1\n");
        return 1;
    }
    // 选择1失败, 将变量反过来赋值
    ClauseHead* original_copy2 = ClauseHead_copy(*node);
    bool_value[abs(unit_value)] = unit_value < 0 ? -1 : 1; // 负值为true
    add_unit_as_clause(&original_copy2, -unit_value);
    // return DPLLsolve(&original_copy2);
    int res = DPLLsolve(&original_copy2);
    if (res) {
        debug("DPLLsolve: 1\n");
    } else {
        debug("DPLLsolve: 0\n");
    }
    return res;
}

int global_init() {
    for (int i = 0; i < 1005; i++) {
        frequency[i] = 0;
        possitive_frequency[i] = 0;
        negative_frequency[i] = 0;
        bool_value[i] = 0;
    }
    debug("global_init: 1\n");
    return 1;
}

int CNF_reader(char input_filename[], char output_filename[]) {
    debug("enter CNF_reader\n");
    FILE* fin = fopen(input_filename, "r");
    if (!fin) {
        debug("CNF_reader: 0\n");
        return 0;
    }
    ClauseHead* head;
    int n; // 多少个子句
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++) {
        int value;
        ClauseHead* new_ClauseHead_node = NULL;
        ClauseHead_init(&new_ClauseHead_node);
        while (fscanf(fin, "%d", &value)) {
            if (value == 0) break;
            new_ClauseHead_node->size++;
            debug("new_ClauseHead_node->size == %d\n", new_ClauseHead_node->size);
            VarNode* new_VarNode = NULL;
            VarNode_init(&new_VarNode);
            new_VarNode->value = value;
            frequency[abs(value)]++;
            if (value > 0) {
                possitive_frequency[value]++;
            } else {
                negative_frequency[-value]++;
            }
            VarNode_push(&new_ClauseHead_node->var_list, new_VarNode);
        }
        ClauseHead_push(&head, new_ClauseHead_node);
    }
    for (int i = 0; i <= 999; i++) {
        if (frequency[i]) {
            debug("frequency[%d]: %d ", i, frequency[i]);
        }
    }
    debug("\n");
    double start = clock();
    FILE* fp = fopen(output_filename, "w");
    if (!fp) {
        debug("CNF_reader: 0\n");
        return 0;
    }
    if (DPLLsolve(&head)) {
        fprintf(fp, "1\n");
        double end = clock();
        double time_elapsed = end - start;
        for (int i = 111; i <= 999; i++) {
            if (bool_value[i]) {
                fprintf(fp, "%d ", bool_value[i] * i);
            }
        }
        fprintf(fp, "\n");
        fprintf(fp, "time elapsed: %.17lfms\n", time_elapsed);
    } else {
        fprintf(fp, "0\n");
        fprintf(fp, "no solution!\n");
        double end = clock();
        double time_elapsed = end - start;
        fprintf(fp, "time elapsed: %.17lfms\n", time_elapsed);
    }
    fclose(fin);
    fclose(fp);
    printf("CNF_reader: 1\n");
    return 1;
}

void test01() {
    CNF_reader("test1.txt", "test1.res");
}

void test02() {
    CNF_reader("test2.txt", "test2.res");
}

int main() {
    global_init();
    test01();
    test02();
    return 0;
}
