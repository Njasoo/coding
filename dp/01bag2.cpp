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
#include <numeric>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> w(n), v(n);
  int sumv = 0;
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
    sumv += v[i];
  }
  const int inf = (int) 1e9;
  vector<vector<int>> dp(n + 1, vector<int>(n * sumv + 1, inf));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n * sumv; j++) {
      if (j < v[i]) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      }
    }
  }
  int res = 0;
  for (int j = 0; j <= n * sumv; j++) {
    if (dp[n][j] <= m) {
      res = j;
    }
  }
  cout << res << '\n';
  return 0;
}