#include <bits/stdc++.h>

using namespace std;

int a[1000005], f[4000005];

void build(int x, int l, int r) {
    if (l == r) {
        f[x] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    f[x] = max(f[x << 1], f[x << 1 | 1]);
}

int find(int x, int l, int r, int s, int e) {
    if (l == s && r == e) {
        return f[x];
    }
    int mid = (l + r) >> 1;
    if (e <= mid) {
        return find(x << 1, l, mid, s, e);
    } else {
        if (s > mid) {
            return find(x << 1 | 1, mid + 1, r, s, e);
        } else {
            return max(find(x << 1, l, mid, s, mid), find(x << 1 | 1, mid + 1, r, mid + 1, e));
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
        int x, y;
        cin >> x >> y;
        cout << find(1, 1, n, x, y) << '\n';
    }
    return 0;
}