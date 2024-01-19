#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#define ll long long
#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 3e3 + 5;
int n, m;
bool vis[N];
vector<pair<int, ll>> g[N];
ll dis[N], h[N];

void dijkstra(int s) {
    memset(vis, 0, sizeof vis);
    for (int i = 0; i <= n; i++) {
        dis[i] = (ll)1e9;
    }
    dis[s] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : g[u]) {
            if (dis[v] > d + w) {
                dis[v] = d + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int v = 1; v <= n; v++) {
        g[0].push_back({v, 0});
    }
    for (int i = 0; i <= n; i++) {
        dis[i] = 1e9;
    }
    dis[0] = 0;
    for (int _ = 1; _ <= n; _++) {
        for (int u = 0; u <= n; u++) {
            for (auto [v, w] : g[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                }
            }
        }
    }
    for (int u = 0; u <= n; u++) {
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        h[i] = dis[i];
        // debug(i, h[i]);
    }
    for (int u = 0; u <= n; u++) {
        for (auto& [v, w] : g[u]) {
            w += h[u] - h[v];
        }
    }
    for (int i = 1; i <= n; i++) {
        dijkstra(i);
        ll ans = 0;
        debug(i);
        for (int j = 1; j <= n; j++) {
            debug(j, dis[j] + h[j] - h[i]);
        }
        for (int j = 1; j <= n; j++) {
            if (dis[j] == (ll)1e9) {
                ans += j * (ll)1e9;
                continue;
            }
            ans += j * (dis[j] + h[j] - h[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}