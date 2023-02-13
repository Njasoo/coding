#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<int> c(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> c[i];
        }
        vector<vector<int>> p(n + 1);
        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        queue<tuple<int, int, int>> q; // (d, x, y)
        vector<vector<int>> dis(n + 1, vector<int>(n + 1, -1));
        q.push({0, 1, n});
        while (!q.empty()) {
            auto [d, x, y] = q.front();
            q.pop();
            if (dis[x][y] != -1) continue;
            dis[x][y] = d;
            for (auto u : p[x]) {
                for (auto v : p[y]) {
                    if (c[u] != c[v]) {
                        q.push({d + 1, u, v});
                    }
                }
            }
        }
        cout << dis[n][1] << '\n';
    }
    return 0;
}