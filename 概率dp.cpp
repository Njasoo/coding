#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 1005;
double dp[N][N]; // dp[i][j] : i个白球, j个黑球, 约翰赢的概率

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    dp[0][0] = 0.0; // 约翰必输
    dp[0][1] = dp[0][2] = dp[0][3] = 0.0;
    dp[1][0] = dp[2][0] = dp[3][0] = 1.0;
    dp[1][1] = 0.5, dp[2][1] = 2.0 / 3;
    dp[1][2] = 1.0 / 3;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i + j <= 3) continue;
            dp[i][j] = 1.0 * i / (i + j);
            if (j >= 3) dp[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
            if (i >= 1 && j >= 2) dp[i][j] += 1.0 * j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
        }
    }
    cout << fixed << setprecision(10) << dp[n][m] << '\n';
    return 0;
}