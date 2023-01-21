n#include <bits/stdc++.h>
using namespace std;
const int N = 105;
double change[N];
double dp[N][2];
// dp[i][0]: 持有美金最大数
// dp[i][1]: 持有马克最大数
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> change[i];
    }   
    dp[1][0] = 100.0;
    dp[1][1] = change[1];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] * 100.0 / change[i]);
        dp[i][1] = max(dp[i - 1][0] * change[i] / 100.0, dp[i - 1][1]);
    }
    cout << fixed << setprecision(2) << dp[n][0] << '\n';
    return 0;
}