#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 5e3 + 5;
vector<pair<int, int>> g[N];
int dis[N], cnt[N];
bool vis[N];
int n, m;

bool spfa() {
    memset(dis, 0x3f, sizeof dis);
    memset(cnt, 0, sizeof cnt);
    dis[0] = 0;
    queue<int> q;
    vis[0] = 1;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (cnt[v] >= n) return 0;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                    cnt[v]++;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[v].push_back({u, w});
    }   
    for (int i = 1; i <= n; i++) {
        g[0].push_back({i, 0});
    }
    if (spfa()) {
        for (int i = 1; i <= n; i++) {
            cout << dis[i] << " \n"[i == n];
        }
    } else {
        cout << "NO\n";
    }
    return 0;
}