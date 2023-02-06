#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int wong[N], p[N], q[N];
int dp[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int s1, s2;
  cin >> s1 >> s2;
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    cin >> wong[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> p[i] >> q[i];
  }
  int T;
  cin >> T;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= T; j++) {
      if (s2 / s1 * wong[p[i]] > j) {
        dp[i][j] = dp[i - 1][j];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s2 / s1 * wong[p[i]]] + q[i]);
      }
    }
  }
  cout << dp[m][T] << '\n';
  return 0;
}