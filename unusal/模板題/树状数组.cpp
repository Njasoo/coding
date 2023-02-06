#include <bits/stdc++.h>

using namespace std;

int n, m, t[500001];

void add(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += x & -x;
    }
}

int sum(int x) {
    int ans = 0;
    while (x) {
        ans += t[x];
        x -= x & -x;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        add(i, a);
    }
    for (int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, k;
            cin >> x >> k;
            add(x, k);
        } else {
            int x, y;
            cin >> x >> y;
            cout << sum(y) - sum(x - 1) << '\n';
        }
    }
    return 0;
}