#include <iostream>
#include <cassert>

using namespace std;

#define Elemtype int // 酷
#define P 13 // 模数

typedef struct HashNode {
    Elemtype data;
    HashNode *link; // 指向下一个链表元素
} HashNode;

typedef HashNode* HashTable[P]; // 哈希数组，长度为P，每个元素类型为指针

// 初始化
void init_HashTable(HashTable& ht) {
    for (int i = 0; i < P; i++) {
        ht[i] = NULL;
    }
}

// 哈希函数
Elemtype Hash(Elemtype x) {
    return x % P;
}

// 哈希的元素增加，增加结点用头插法
void Insert_HashTable(HashTable& ht, Elemtype x) {
    Elemtype index = Hash(x); // 通过哈希函数求出下标
    HashNode* s = (HashNode*)malloc(sizeof(HashNode));
    assert(s);
    s->data = x;
    // 头插法
    s->link = ht[index];
    ht[index] = s;
}

// 哈希的显示
void Show_HashTable(HashTable& ht) {
    for (int i = 0; i < P; i++) {
        printf("%2d", i);
        printf(": ");
        HashNode* p = ht[i];
        while (p) {
            printf("%d-->", p->data);
            p = p->link; // 如果有冲突，p就可以指向下一个与该元素有冲突的元素，否则指向空
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable ht;
    // 待插入到哈希表的数组
    Elemtype arr[] = {19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79};
    int sz = sizeof(arr) / sizeof(Elemtype);
    for (int i = 0; i < sz; i++) {
        Insert_HashTable(ht, arr[i]);
    }
    printf("The hashtable ht is like:\n");
    Show_HashTable(ht);
    return 0;
}
