#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 1005, M = 105, INF = 0x3f3f3f3f;
int n, m, v, ex, ey, ans = INF;
int id[N][M], dis[N * M];
vector<pair<int, int>> g[N * M];
bool vis[N * M];

void dijkstra(int s) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    dis[s] = 0;
    q.push({dis[s], s});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u] == 1) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (d + w < dis[v]) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
    }
    // db(dis[id[ex][ey]]);
    ans = min(ans, dis[id[ex][ey]]);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v >> ex >> ey;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            id[i][j] = ++cnt;
            // which_floor[cnt] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x, y;
            cin >> x >> y;
            g[id[i][j]].push_back({id[x][y], abs(x - i) * v});
            // cerr << "(" << i << ", " << j << ")" << " -> " << "(" << x << ", " << y << ")";
            // db(abs(x - i) * v);
        }
    }
    for (int j = 1; j <= m; j++) {
        dijkstra(id[1][j]);
    }
    if (ans == INF) {
        cout << "impossible\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}