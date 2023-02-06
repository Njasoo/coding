#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;
int n, m, cnt = 0;
int dis[2005], head[20005];
bool vis[2005];
struct Edge {
  int from, to, cost, nex;
}e[200005];
struct node {
  int w, now;

  bool operator < (const node &x) const {
    return w > x.w;
  }
};
priority_queue<node> q;

void add(int from, int to, int cost) {
  cnt += 1;
  e[cnt].from = from;
  e[cnt].to = to;
  e[cnt].cost = cost;
  e[cnt].nex = head[from];
  head[from] = cnt;
}

void dijkstra(int s) {
  for (int i = 1; i <= n * 2; i++) {
    dis[i] = inf;
  }
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    node x = q.top();
    q.pop();
    int u = x.now;
    if (vis[u]) continue;
    vis[u] = true;
    for (int i = head[u]; i != 0; i = e[i].nex) {
      int v = e[i].to;
      if (dis[u] + e[i].cost < dis[v]) {
        dis[v] = dis[u] + e[i].cost;
        q.push({dis[v], v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    add(u, v, w);
    add(v + n, u + n, w);
  }
  dijkstra(1);
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    ans += dis[i];
  }
  dijkstra(1 + n);
  for (int i = n + 2; i <= n * 2; i++) {
    ans += dis[i];
  }
  cout << ans << '\n';
  return 0;
}