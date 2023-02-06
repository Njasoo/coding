#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  const int mod = 80112002;
  vector<vector<int>> p(n + 1);
  vector<int> f(n + 1), ind(n + 1), outd(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    ++outd[x], ++ind[y];
    p[x].push_back(y);
  }
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (ind[i] == 0) {
      q.push(i);
      f[i] = 1;
    }
  }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < (int) p[x].size(); i++) {
      int y = p[x][i];
      f[y] = (f[x] + f[y]) % mod;
      if (--ind[y] == 0) {
        q.push(y);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (outd[i] == 0) {
      ans = (ans + f[i]) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}