#include <bits/stdc++.h>
using namespace std;
// 2 3 4 5
// 6  7 8 ...
const int N = 105;
const int INF = 0x3f3f3f3f;
int f[N][N], id[N][N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
struct Edge {
    int to, cost, nex;
} e[N * N * 2];
struct Node {
    int w, now;
    bool operator < (const Node& x) const {
        return x.w < w;
    }
};
int head[N * N], idx;
void add_edge(int u, int v, int w) {
    idx++;
    e[idx].to = v;
    e[idx].cost = w;
    e[idx].nex = head[u];
    head[u] = idx;
}
int dis[N * N], vis[N * N];
priority_queue<Node> q;
void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    dis[id[1][1]] = 0;
    q.push({0, id[1][1]});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nex) {
            int v = e[i].to, w = e[i].cost;
            if (d + w < dis[v]) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            id[i][j] = ++cnt;
        }
    }
    // cout << "test: " << id[1][1] << " " << id[2][2] << '\n';
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        f[x][y] = c + 1; // 0代表没有颜色
    }
    f[n][n + 1] = 1; // 以防终点没有颜色, 到达这两个位置等价于用魔法给终点染上颜色
    f[n + 1][n] = 2; 
    // n++;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
            if (f[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int dx = dir[k][0], dy = dir[k][1];
                    int nx = i + dx, ny = j + dy;
                    if (nx < 1 || nx > n + 1 || ny < 1 || ny > n + 1) continue;
                    if (f[nx][ny]) {
                        add_edge(id[i][j], id[nx][ny], f[i][j] == f[nx][ny] ? 0 : 1);
                    } else {
                        for (int kk = 0; kk < 4; kk++) {
                            int ddx = dir[kk][0], ddy = dir[kk][1];
                            int nnx = nx + ddx, nny = ny + ddy;
                            if (nnx < 1 || nnx > n + 1 || nny < 1 || nny > n + 1) continue;
                            // if (nnx == i && nny == j) continue;
                            if (!f[nnx][nny]) continue;
                            add_edge(id[i][j], id[nnx][nny], f[i][j] == f[nnx][nny] ? 2 : 3);
                            add_edge(id[nnx][nny], id[i][j], f[i][j] == f[nnx][nny] ? 2 : 3);
                        }
                    }
                }
            }
        }
    }
    dijkstra();
    int ans = min(dis[id[n][n + 1]], dis[id[n + 1][n]]);
    if (ans == INF) { 
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}