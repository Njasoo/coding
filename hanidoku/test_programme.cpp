#include <cstdio>
#include <cstdlib>
#include <cassert>

#ifdef LOCAL
#define debug printf
#else
#define debug(...) 114514
#endif

// 子句的变量结点
typedef struct VarNode {
    int value;
    struct VarNode* next;
} VarNode;

int VarNode_init(VarNode** node) {
    debug("enter VarNode_init\n");
    // 创建新的结点并且初始化, 然后插入到当前链表尾端, 并且返回尾端结点以便于操作
    assert(!(*node));
    // if (*node) { // 已经被初始化
    //     printf("VarNode_init: 0\n"); // 理论上程序中不应该返回0
    //     return 0;
    // }
    *node = (VarNode*) malloc(sizeof(VarNode));
    (*node)->next = NULL;
    (*node)->value = 0;
    debug("VarNode_init: 1\n");
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
    debug("enter VarNode_find\n");
    VarNode* p = node;
    while (p) {
        if (p->value == value) {
            printf("VarNode_find: 1\n");
            return 1; // 找到
        }
        p = p->next;
    }
    debug("VarNode_find: 0\n");
    return 0; // 找不到
}

int VarNode_push(VarNode** head, VarNode* node) { // 插入新的VarNode带链表尾端
    debug("enter VarNode_push\n");
    if (*head == NULL) {
        *head = node;
        debug("VarNode_push: 1\n");
        return 1;
    }
    VarNode* p = *head;
    while (p->next) {
        p = p->next;
    }
    p->next = node;
    debug("VarNode_push: 1\n");
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
            VarNode_print(*node);
            debug("deleted1, p->value: %d\n", p->value);
            VarNode_print(*node);
            free(p);
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
            VarNode_print(*node);
            debug("deleted2, p->value: %d\n", p->value);
            VarNode* nex = p->next;
            pre->next = nex;
            VarNode_print(*node);
            free(p);
            cnt++;
            p = nex;
        } else {
            pre = p;
            p = nex;
        }
    }
    debug("\n");
    debug("VarNode_delete: %d\n", cnt);
    return cnt;
}

int main() {
    VarNode* head = NULL;
    VarNode* new_VarNode1 = NULL;
    VarNode_init(&new_VarNode1);
    new_VarNode1->value = -11;
    VarNode* new_VarNode2 = NULL;
    VarNode_init(&new_VarNode2);
    new_VarNode2->value = 14;
    VarNode* new_VarNode3 = NULL;
    VarNode_init(&new_VarNode3);
    new_VarNode3->value = 9;
    VarNode_push(&head, new_VarNode1);
    VarNode_push(&head, new_VarNode2);
    VarNode_push(&head, new_VarNode3);
    if (VarNode_find(head, 1)) printf("yes: 1\n");
    else printf("no: 0\n");
    VarNode_delete(&head, 9);
    return 0;
}