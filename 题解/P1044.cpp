#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][N];
int solve(int u, int v) {
    if (dp[u][v] != -1) return dp[u][v];
    if (!u) return 1;
    if (v < 0) return 0;
    int res = solve(u - 1, v + 1); // 进栈
    res += solve(u, v - 1); // 出栈
    return dp[u][v] = res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    cout << solve(n, 0) << '\n';
    return 0;
}