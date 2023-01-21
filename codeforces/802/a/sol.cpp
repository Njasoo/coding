#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    auto cost = [&](int x, int y) {
        return (x - 1) * m + y;
    };

    long long cost1 = 0, cost2 = 0;

    for (int i = 1; i <= n; i++) {
        cost1 += cost(i, 1);
    }
    for (int j = 2; j <= m; j++) {
        cost1 += cost(n, j);
    }

    for (int j = 1; j <= m; j++) {
        cost2 += cost(1, j);
    }
    for (int i = 2; i <= n; i++) {
        cost2 += cost(i, m);
    }

    cout << min(cost1, cost2) << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt;
    cin >> tt;

    while (tt--) {
        solve();
    }
    
    return 0;
}