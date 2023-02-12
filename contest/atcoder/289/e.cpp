#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 2e3 + 5;
struct node {
    int step, x, y;
};
vector<int> p[N];
int c[N];
int dis[N][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        memset(dis, -1, sizeof(dis));
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
            p[i].clear();
        }
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        queue<node> q;
        q.push({0, 1, n});
        while (!q.empty()) {
            node now = q.front();
            q.pop();
            int x = now.x, y = now.y, d = now.step;
            if (dis[x][y] != -1) continue;
            dis[x][y] = d;
            for (auto u : p[x]) {
                for (auto v : p[y]) {
                    if (c[u] != c[v]) { // 每人各走一步，颜色不一样就踩上去
                        q.push({d + 1, u, v});
                    }
                }
            }
        }
        cout << dis[n][1] << '\n'; // 最后是1走到n，n走到1
    }
    return 0;
}