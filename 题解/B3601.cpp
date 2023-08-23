#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    vector<long long> dis(n, LONG_LONG_MAX);
    dis[0] = 0;
    q.push({0, 0});
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
    for (int i = 0; i < n; i++) {
        if (dis[i] == LONG_LONG_MAX) cout << "-1 ";
        else cout << dis[i] << " ";
    }
    cout << '\n';
    return 0;
}