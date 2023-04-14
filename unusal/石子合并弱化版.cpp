#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define sz(x) (int)(x).size()
const int N = 305;
long long dp[N][N];
long long a[N], sum[N];
// 短区间到长区间
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, 0x3f, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            for (int k = i; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    cout << dp[1][n] << '\n';
    return 0;
}