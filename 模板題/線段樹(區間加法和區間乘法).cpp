#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <climits>

using namespace std;

int p;

long long a[100001];
struct node {
    long long val, mul, add;
}t[400001];

void build(int x, int left, int right) {
    t[x].mul = 1;
    t[x].add = 0;
    if (left == right) {
        t[x].val = a[left];
    } else {
        int mid = (left + right) / 2;
        build(x * 2, left, mid);
        build(x * 2 + 1, mid + 1, right);
        t[x].val = t[x * 2].val + t[x * 2 + 1].val;
    }
    t[x].val %= p;
}

void push_down(int x, int left, int right) {
    int mid = (left + right) / 2;
    t[x * 2].val = (t[x * 2].val * t[x].mul + t[x].add * (mid - left + 1)) % p;
    t[x * 2 + 1].val = (t[x * 2 + 1].val * t[x].mul + t[x].add * (right - mid)) % p;
    t[x * 2].mul = (t[x * 2].mul * t[x].mul) % p;
    t[x * 2 + 1].mul = (t[x * 2 + 1].mul * t[x].mul) % p;
    t[x * 2].add = (t[x * 2].add * t[x].mul + t[x].add) % p;
    t[x * 2 + 1].add = (t[x * 2 + 1].add * t[x].mul + t[x].add) % p;
    t[x].mul = 1;
    t[x].add = 0;
}

void update_mul(int x, int left, int right, int s, int e, long long k) {
    if (e < left || s > right) {
        return;
    }
    if (s <= left && right <= e) {
        t[x].val = (t[x].val * k) % p;
        t[x].mul = (t[x].mul * k) % p;
        t[x].add = (t[x].add * k) % p;
        return;
    }
    push_down(x, left, right);
    int mid = (left + right) / 2;
    update_mul(x * 2, left, mid, s, e, k);
    update_mul(x * 2 + 1, mid + 1, right, s, e, k);
    t[x].val = (t[x * 2].val + t[x * 2 + 1].val) % p;
}

void update_add(int x, int left, int right, int s, int e, long long k) {
    if (e < left || s > right) {
        return;
    }
    if (s <= left && right <= e) {
        t[x].val = (t[x].val + k * (right - left + 1)) % p;
        t[x].add = (t[x].add + k) % p;
        return;
    }
    push_down(x, left, right);
    int mid = (left + right) / 2;
    update_add(x * 2, left, mid, s, e, k);
    update_add(x * 2 + 1, mid + 1, right, s, e, k);
    t[x].val = (t[x * 2].val + t[x * 2 + 1].val) % p;
}

long long query(int x, int left, int right, int s, int e) {
    if (e < left || s > right) {
        return 0;
    }
    if (s <= left && right <= e) {
        return t[x].val;
    }
    push_down(x, left, right);
    int mid = (left + right) / 2;
    return (query(x * 2, left, mid, s, e) + query(x * 2 + 1, mid + 1, right, s, e)) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            long long k;
            cin >> x >> y >> k;
            update_mul(1, 1, n, x, y, k);
        } else if (op == 2) {
            int x, y;
            long long k;
            cin >> x >> y >> k;
            update_add(1, 1, n, x, y, k);
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}