#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dp[N][2], a[N];
// dp[i][0]: 表示不移动盖子的情况下最大不被雨淋的数量，dp[i][1]表示移动盖子的情况下最大不被雨淋的数量
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (s[1] == '1') {
            dp[1][0] = a[1];
        }
        for (int i = 2; i <= n; i++) {
            if (s[i] == '1') {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + a[i];
                if (s[i - 1] == '1') dp[i][1] = dp[i - 1][1] + a[i - 1];
                else dp[i][1] = dp[i - 1][0] + a[i - 1];
            } else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        cout << max(dp[n][0], dp[n][1]) << '\n';
    }   
    return 0;
}