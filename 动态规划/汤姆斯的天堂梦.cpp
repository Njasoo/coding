#include <bits/stdc++.h>

using namespace std;

int dp[105][105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = 1e9;
            int num, cost;
            cin >> num;
            while (num != 0) {
                cin >> cost;
                dp[i][j] = min(dp[i][j], dp[i - 1][num] + cost);
                cin >> num;
            }
        }
    }      
    int ans = 1e9;
    for (int j = 1; j <= k; j++) {
        ans = min(ans, dp[n][j]);
    }
    cout << ans << '\n';
    return 0;
}