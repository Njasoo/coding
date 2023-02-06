#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <functional>
#include <ctime>
#include <cassert>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  // dp[i][j]: the len of s1...si and t1...tj's LCS
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }
  }
  cout << dp[n][m] << '\n';
  return 0;
}