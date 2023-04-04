#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
long long k[N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    sort(k + 1, k + 1 + n);
    for (int i = 1; i <= m; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        int pos1 = lower_bound(k + 1, k + 1 + n, b) - k;
        if (pos1 != n + 1) {
            if (b - 2 * sqrtl(a * c) < k[pos1] && k[pos1] < b + 2 * sqrtl(a * c)) {
                cout << "YES\n";
                cout << k[pos1] << "\n";
                continue;
            }
        }
        if (pos1 != 1) {
            if (b - 2 * sqrtl(a * c) < k[pos1 - 1] && k[pos1 - 1] < b + 2 * sqrtl(a * c)) {
                cout << "YES\n";
                cout << k[pos1 - 1] << "\n";
                continue;
            }
        }
        cout << "NO\n";
    }
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