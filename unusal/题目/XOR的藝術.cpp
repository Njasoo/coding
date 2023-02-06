#include <cstdio>

using namespace std;

int a[200001];
struct node {
    int val, tag;
}t[800001];

void build(int id, int left, int right) {
    t[id].tag = 0;
    if (left == right) {
        t[id].val = a[left];
        return;
    }
    int mid = (left + right) >> 1;
    build(id << 1, left, mid);
    build(id << 1 | 1, mid + 1, right);
    t[id].val = t[id << 1].val + t[id << 1 | 1].val;
}

void push_down(int id, int left, int right) {
    if (t[id].tag) {
        int mid = (left + right) >> 1;
        t[id << 1].val = (mid - left + 1) - t[id << 1].val;
        t[id << 1 | 1].val = (right - mid) - t[id << 1 | 1].val;
        t[id << 1].tag ^= 1;
        t[id << 1 | 1].tag ^= 1;
        t[id].tag = 0;
    }
}

void update(int id, int left, int right, int s, int e) {
    if (e < left || s > right) {
        return;
    }
    if (s <= left && right <= e) {
        t[id].val = (right - left + 1) - t[id].val;
        t[id].tag ^= 1;
        return;
    }
    push_down(id, left, right);
    int mid = (left + right) >> 1;
    update(id << 1, left, mid, s, e);
    update(id << 1 | 1, mid + 1, right, s, e);
    t[id].val = t[id << 1].val + t[id << 1 | 1].val;
}

int query(int id, int left, int right, int s, int e) {
    if (e < left || s > right) {
        return 0;
    }
    if (s <= left && right <= e) {
        return t[id].val;
    }
    push_down(id, left, right);
    int mid = (left + right) >> 1;
    return query(id << 1, left, mid, s, e) + query(id << 1 | 1, mid + 1, right, s, e);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%1d", &a[i]);
    }   
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op, l, r;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 0) {
            update(1, 1, n, l, r);
        } else {
            printf("%d\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}