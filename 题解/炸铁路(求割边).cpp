#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<pair<int, int>> e;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        e.push_back({u, v});
    }
    vector<vector<int>> d(n, vector<int>(n, 0));
    auto bfs = [&]() -> int {
        int res = 0;
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (vis[u]) continue;
            vis[u] = 1;
            res++;
            for (int v : g[u]) {
                if (d[u][v]) continue;
                q.push(v);
            }
        }
        return res;
    };
    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++) {
        int u = e[i].first;
        int v = e[i].second;
        d[u][v] = d[v][u] = 1;
        // cerr << ": " << bfs() << '\n';
        if (bfs() != n) {
            if (v < u) swap(u, v);
            ans.push_back({u, v});
        }
        d[u][v] = d[v][u] = 0;
    }
    sort(ans.begin(), ans.end());
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << '\n';
    }
    return 0;
}