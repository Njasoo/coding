#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, s;
  cin >> n >> m >> s;
  const int inf = (int) 1e9;
  vector<vector<int>> a(n + 1, vector<int>(n + 1, inf));
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u][v] = min(a[u][v], w);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      if (i == k || a[i][k] == inf) continue;
      for (int j = 1; j <= n; j++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  a[s][s] = 0;
  for (int i = 1; i <= n; i++) {
    cout << a[s][i] << " \n"[i == n];
  }
  return 0;
}