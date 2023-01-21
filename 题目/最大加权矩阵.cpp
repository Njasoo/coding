#include <bits/stdc++.h>

using namespace std;

// 區間求和 + 最大子序列
// 先求每一列的前綴和
// 指定起始行和終結行，把二維壓縮成一維
// 然後按照最大子序列的流程做就好

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> f(n + 1, vector<int>(n + 1));
  vector<vector<int>> sum(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> f[i][j];
      sum[i][j] = sum[i - 1][j] + f[i][j];
    }
  } 
  int ans = -INT_MAX;
  for (int s = 1; s < n; s++) {
    for (int e = s + 1; e <= n; e++) {
      vector<int> dp(n + 1);
      for (int j = 1; j <= n; j++) {
        int cnt = sum[e][j] - sum[s - 1][j];
        dp[j] = max(dp[j - 1] + cnt, cnt);
        ans = max(ans, dp[j]);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}