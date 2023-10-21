#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> f(n);
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        int ans = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int sum = f[i][j] + f[j][n - 1 - i] + f[n - 1 - i][n - 1 - j] + f[n - 1 - j][i];
                int mx = max({f[i][j], f[j][n - 1 - i], f[n - 1 - i][n - 1 - j], f[n - 1 - j][i]});
                ans += mx * 4 - sum;
            }
        }
        cout << ans << '\n';
    }   
    return 0;
}