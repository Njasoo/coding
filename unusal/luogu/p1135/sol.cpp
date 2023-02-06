#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> k(n + 1), vis(n + 1), ans(n + 1, -1);
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
  }
  queue<int> q;
  q.push(a);
  ans[a] = 0;
  vis[a] = true;
  if (a == b) {
    cout << 0 << '\n';
    return 0;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = -1; i <= 1; i += 2) {
      int dist = u + k[u] * i;
      if (dist == b) {
        cout << ans[u] + 1 << '\n';
        return 0;
      }
      if (dist >= 1 && dist <= n && ans[dist] == -1) {
        ans[dist] = ans[u] + 1;
        q.push(dist);
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}