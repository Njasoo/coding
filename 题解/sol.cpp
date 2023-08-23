#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      --u, --v;
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({0, 0});
    const long long inf = (long long) 1e18;
    vector<long long> dis(n, inf);
    vector<bool> vis(n);
    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      if (vis[u]) continue;
      vis[u] = true;
      for (auto [v, w] : g[u]) {
        if (d + w < dis[v]) {
          dis[v] = d + w;
          q.push({dis[v], v});
        }
      }
    }
  }
  return 0;
}