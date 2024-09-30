#include <bits/stdc++.h>

using namespace std;

#define i64 long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < k; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        g[x][y] = c;
    }
    vector<vector<i64>> dp(1 << n, vector<i64>(n));
    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = a[i];
    }
    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                for (int j = 0; j < n; j++) {
                    if (j != i && mask >> j & 1) {
                        dp[mask][i] = max(dp[mask][i], dp[mask - (1 << i)][j] + g[j][i] + a[i]);
                    }
                }
            }
        }
    }
    i64 ans = 0;
    for (int mask = 0; mask < 1 << n; mask++) {
        if (__builtin_popcount(mask) != m) continue;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dp[mask][i]);
        }
    }
    cout << ans << '\n';
    return 0;
}