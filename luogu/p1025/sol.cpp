/**
 *    author:  Njaso
 *    created: 05.07.2022 20:30:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> dp(n + 1, vector<int>(k + 1));
  for (int i = 1; i <= n; i++) {
    dp[i][1] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j <= k; j++) {
      if (i >= j) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
      } else {
        dp[i][j] = dp[i - 1][j - 1];
      }
    }
  }
  cout << dp[n][k] << '\n';
  return 0;
}