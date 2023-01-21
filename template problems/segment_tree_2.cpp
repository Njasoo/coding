#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N];
long long f[N * 4], v[N * 4];

void build(int k, int l, int r) {
    if (l == r) {
        f[k] = a[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(k << 1, l, m);
    build(k << 1 | 1, m + 1, r);
    f[k] = f[k << 1] + f[k << 1 | 1];
}

void add(int k, int l, int r, int x, int y, long long z) {
    if (l == x && r == y) {
        v[k] += z;
        return;
    }
    f[k] += (y - x + 1) * z;
    int m = l + (r - l) / 2;
    if (y <= m) {
        add(k << 1, l, m, x, y, z);
    } else {
        if (x > m) {
            add(k << 1 | 1, m + 1, r, x, y, z);
        } else {
            add(k << 1, l, m, x, m, z);
            add(k << 1 | 1, m + 1, r, m + 1, y, z);
        }
    }
}

long long calc(int k, int l, int r, int s, int e, long long p) {
    p += v[k];
    if (l == s && r == e) {
        return f[k] + p * (r - l + 1);
    }
    int m = l + (r - l) / 2;
    if (e <= m) {
        return calc(k << 1, l, m, s, e, p);
    } else {
        if (s > m) {
            return calc(k << 1 | 1, m + 1, r, s, e, p);
        } else {
            return calc(k << 1, l, m, s, m, p) + calc(k << 1 | 1, m + 1, r, m + 1, e, p);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(1, 1, n, x, y, k);
        } else {
            int x, y;
            cin >> x >> y;
            cout << calc(1, 1, n, x, y, 0) << '\n';
        }
    }
    return 0;
}