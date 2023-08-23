#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 100005;
int a[M], dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dp[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i < m; i++) {
        ans += dp[a[i]][a[i + 1]];
    }
    cout << ans << '\n';
    return 0;
}