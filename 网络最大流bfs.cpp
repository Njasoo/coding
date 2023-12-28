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

const int N = 205;
const int M = 1e4 + 5;
long long tag[N][N], dis[N], head[N], cnt, n, m, s, t, vis[N], pre_e[N], ans;
struct Edge {
    long long to, cost, nex;
} e[M];

void add_edge(int u, int v, int w) {
    e[cnt].to = v;
    e[cnt].cost = w;
    e[cnt].nex = head[u];
    head[u] = cnt;
    // debug(u, head[u]);
    tag[u][v] = cnt;
    cnt++;
}

bool bfs() {
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    vis[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // debug(u, head[u]);
        for (int i = head[u]; i != -1; i = e[i].nex) {
            long long v = e[i].to, w = e[i].cost;
            if (vis[v] || w == 0) continue;
            vis[v] = 1;
            pre_e[v] = i;
            // debug(u, v, w);
            dis[v] = min(dis[u], w);
            // debug(v, dis[v]);
            if (v == t) {
                return 1;
            }
            // debug(v);
            q.push(v);
        }
    }
    return 0;
}

void update() {
    int now = t;
    while (now != s) {
        int edge_id = pre_e[now];
        e[edge_id].cost -= dis[t];
        e[edge_id ^ 1].cost += dis[t];
        now = e[edge_id ^ 1].to;
    }
    ans += dis[t];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(head, -1, sizeof head);
    memset(tag, -1, sizeof tag);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        if (tag[u][v] == -1) {
            add_edge(u, v, w);
            add_edge(v, u, 0);
        } else {
            int temp = tag[u][v];
            e[temp].cost += w;
        }
    }
    while (bfs()) {
        // cerr << "hi\n";
        update();
    }
    cout << ans << '\n';
    return 0;
}