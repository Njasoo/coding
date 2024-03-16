#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dis(n, vector<int>(k, 1e9));
    vector<bool> vis(n);
    auto bfs = [&](int color) -> void {
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (a[i] == color) {
                q.push(i);
                dis[i][color] = 0;
            }
        }
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            if (vis[u]) {
                continue;
            }
            vis[u] = true;
            for (auto v : adj[u]) {
                if (dis[v][color] > dis[u][color] + 1) {
                    dis[v][color] = dis[u][color] + 1;
                    q.push(v);
                }
            }
        }
    };
    for (int i = 0; i < k; i++) {
        bfs(i);
    }
    for (int i = 0; i < n; i++) {
        sort(dis[i].begin(), dis[i].end());
        cout << accumulate(dis[i].begin(), dis[i].end() + s, 0LL) << " \n"[i == n - 1];
    }
    return 0;
}