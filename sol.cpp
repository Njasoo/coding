#include <bits/stdc++.h>
using namespace std;
int m[105], t[105];
int dp[105][205][205];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, M, T;
    cin >> n >> M >> T;
    for (int i = 1; i <= n; i++) {
        cin >> m[i] >> t[i];
    }   
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= M; j++) {
            for (int k = 0; k <= T; k++) {
                if (j >= m[i] && k >= t[i]) {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - m[i]][k - t[i]] + 1);
                } else {
                    dp[i][j][k] = dp[i - 1][j][k];
                }
            }
        }
    }
    cout << dp[n][M][T] << '\n';
    return 0;
}