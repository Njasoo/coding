#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int MN = 100;
int n, x;
int a[MN + 5][2];
int dp[MN + 5][MN + 5];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = x; j >= 0; j--) {
            for (int k = 0; k < 2; k++) {
                if (a[i][k] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[j][k]] + a[i][k]);
                }
            }
        }
    }
    cout << dp[n][x] << '\n';
    return 0;
}