#include <bits/stdc++.h>

using namespace std;

/*
造两个线段树
一个维护区间最小值, 另一个维护区间最大值
每次寻找是2logn
所以时间复杂度是O(qlogn)
*/

const int inf = (int) 1e9;
int h[50005];
struct node {
    int max_val, min_val;
}t[200005];

void build(int id, int left, int right) {
    if (left == right) {
        t[id].max_val = h[left];
        t[id].min_val = h[left];
        return;
    }
    int mid = (left + right) / 2;
    build(id * 2, left, mid);
    build(id * 2 + 1, mid + 1, right);
    t[id].max_val = max(t[id * 2].max_val, t[id * 2 + 1].max_val);
    t[id].min_val = min(t[id * 2].min_val, t[id * 2 + 1].min_val);
}

int find_max(int id, int left, int right, int s, int e) {
    if (left == s && right == e) {
        return t[id].max_val;
    }
    int mid = (left + right) / 2;
    if (e <= mid) {
        return find_max(id * 2, left, mid, s, e);
    } else {
        if (s > mid) {
            return find_max(id * 2 + 1, mid + 1, right, s, e);
        } else {
            return max(find_max(id * 2, left, mid, s, mid), find_max(id * 2 + 1, mid + 1, right, mid + 1, e));
        }
    }
}

int find_min(int id, int left, int right, int s, int e) {
    if (left == s && right == e) {
        return t[id].min_val;
    }
    int mid = (left + right) / 2;
    if (e <= mid) {
        return find_min(id * 2, left, mid, s, e);
    } else {
        if (s > mid) {
            return find_min(id * 2 + 1, mid + 1, right, s, e);
        } else {
            return min(find_min(id * 2, left, mid, s, mid), find_min(id * 2 + 1, mid + 1, right, mid + 1, e));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        cout << find_max(1, 1, n, a, b) - find_min(1, 1, n, a, b) << "\n";
    }
    return 0;
}