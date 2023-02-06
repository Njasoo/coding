/**
 *    author:  Njaso
 *    created: 03.06.2022 21:24:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, s, a, b;
  cin >> n >> s >> a >> b;
  vector<int> x(n + 1), y(n + 1);
  vector<vector<int>> dp(n + 1, vector<int>(s + 1));
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s; j++) {
      if (j >= y[i] && a + b >= x[i]) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - y[i]] + 1);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n][s] << '\n';
  return 0;
}