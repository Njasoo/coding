#include <iostream>
#include <cassert>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define Elemtype int // 酷
#define P 13 // 模数

typedef struct HashNode {
    Elemtype data;
    HashNode *link; // 指向下一个链表元素
    // 相同哈希值的放在同一个链表里面
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

// 哈希的查找
HashNode* Search_HashTable(HashTable& ht, Elemtype key) {
    Elemtype index = key % P;
    HashNode* p = ht[index];
    while (p) {
        if (p->data == key) return p;
        else p = p->link;
    }
    return NULL;
}

// 哈希的删除
bool Remove_HashTable(HashTable& ht, Elemtype key1) {
    HashNode* p = Search_HashTable(ht, key1);
    if (!p) return 0; // 根本没有这个对应的值
    HashNode* q; // 要删除的前驱结点
    Elemtype index = Hash(key1);
    q = ht[index];
    if (q == p) { // 说明是第一个结点
        ht[index] = q->link;
        free(q);
        return 1;
    }
    while (q && q->link->data != key1) { // 找到p的前驱结点
        q = q->link;
    }
    q->link = p->link;
    free(p);
    return 1;
}

int main() {
    HashTable ht;
    init_HashTable(ht); // 忘记初始化了干
    // 待插入到哈希表的数组
    Elemtype arr[] = {19, 14, 23, 01, 68, 20, 84, 27, 55, 11, 10, 79, 19};
    // 还可以搞个什么查重之类的
    int len = sizeof(arr) / sizeof(Elemtype);
    sort(arr, arr + len);
    int sz = unique(arr, arr + len) - arr;
    for (int i = 0; i < sz; i++) {
        Insert_HashTable(ht, arr[i]);
    }
    printf("The hashtable ht is like:\n");
    Show_HashTable(ht);

    Elemtype key = 19;
    HashNode* p = Search_HashTable(ht, key);
    if (p) {
        printf("finded: %d\n", p->data);
    } else {
        printf("can't find the data\n");
    }

    Elemtype key1 = 27;
    if (Remove_HashTable(ht, key1)) {
        printf("Delete successfully\n");
    } else {
        printf("Deletetion failed\n");
    }
    Show_HashTable(ht);
    return 0;
}
