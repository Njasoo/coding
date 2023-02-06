#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
const int MN = 1e7;
long long dp[MN * 2 + 5];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    int n, x, y;
    cin >> n >> x >> y;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + x);
        dp[i] = min(dp[i], dp[i + 1] + x);
        dp[i * 2] = min(dp[i * 2], dp[i] + y);
    }
    cout << dp[n] << '\n';
    return 0;
}