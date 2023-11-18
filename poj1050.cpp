#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 105;
long long f[N][N], sum[N][N], dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> f[i][j];
        }
    }   
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sum[j][i] = sum[j][i - 1] + f[i][j];
        }
    }
    long long ans = -1e18;
    for (int row1 = 1; row1 <= n; row1++) {
        for (int row2 = row1; row2 <= n; row2++) {
            memset(dp, 0, sizeof(dp));
            for (int i = 1; i <= n; i++) {
                long long temp = sum[i][row2] - sum[i][row1 - 1];
                dp[i] = max(dp[i - 1] + temp, temp);
                ans = max(ans, dp[i]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}