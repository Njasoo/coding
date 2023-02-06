#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
int m, n;
int a[N], b[N], c[N];
int dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 1; i <= n; i++) {
    map<int, bool> hs;
    for (int j = 0; j <= m; j++) {
      if (a[i] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
      }
    }
  }
  return 0;
}