#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
const int MOD = 1e6 + 7;
const int N = 105;
int a[N], dp[N][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }  
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= a[i]; k++) {
                if (j - k >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
    return 0;
}