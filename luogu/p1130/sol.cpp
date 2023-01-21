#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
int a[N][N], f[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[j][i];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j] = min(f[i - 1][j], j == 1 ? f[i - 1][m] : f[i - 1][j - 1]) + a[i][j];
    }
  }
  const int inf = (int) 1e9;
  int ans = inf;
  for (int i = 1; i <= m; i++) {
    ans = min(ans, f[n][i]);
  }
  cout << ans << '\n';
  return 0;
}