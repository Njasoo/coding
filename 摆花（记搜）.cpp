#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
// dp[i][j] : 前i种花总共j盆的摆放方案
const int N = 105;
const int MOD = 1e6 + 7;
int n, m;
int a[N], dp[N][N];
int solve(int now, int tot) {
    if (tot == m) return 1; // 这个应该放在前面
    if (tot > m || now > n) return 0;
    if (dp[now][tot] != -1) return dp[now][tot];
    int res = 0;
    for (int i = 0; i <= a[now]; i++) { // 决定放几盆
        res = (res + solve(now + 1, tot + i)) % MOD;
    }
    return dp[now][tot] = res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;   
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << solve(1, 0) << '\n';
    return 0;
}