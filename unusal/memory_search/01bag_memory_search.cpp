#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> w(n), v(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i] >> v[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  function<int(int, int)> dfs = [&](int i, int j) {
    if (dp[i][j] >= 0) return dp[i][j];
    int res;
    if (i == n) {
      res = 0;
    } else if (j < w[i]) {
      res = dfs(i + 1, j);
    } else {
      res = max(dfs(i + 1, j), dfs(i + 1, j - w[i]) + v[i]);
    }
    return dp[i][j] = res;
  };
  cout << dfs(0, m) << '\n';
  return 0;
}