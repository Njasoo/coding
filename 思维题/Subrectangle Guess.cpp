#include <bits/stdc++.h>

using namespace std;

int f[55][55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        const int inf = 1e9;
        int mx = -inf, max_h = 0, max_w = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> f[i][j];
                if (f[i][j] >= mx) {
                    mx = f[i][j];
                    max_h = max(i, n - i + 1);
                    max_w = max(j, m - j + 1);
                }
            }
        }
        cout << max_h * max_w << '\n';
    }      
    return 0;
}