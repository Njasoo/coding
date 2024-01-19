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

const int N = 1e3 + 5;
const int M = 5e5 + 5;

struct Edge {
    long long to, cost, nex;
} e[M];
int head[N], idx, cnt[N];
int n, ml, md;
long long dis[N];
bool vis[N];

void add_edge(long long u, long long v, long long w) {
    idx++;
    e[idx].to = v;
    e[idx].cost = w;
    e[idx].nex = head[u];
    head[u] = idx;
}

bool spfa() {
    for (int i = 0; i <= n; i++) {
        dis[i] = 1e18;
        vis[i] = 0;
    }

    queue<int> q;
    vis[1] = 1;
    dis[1] = 0;
    q.push(1);

    // vis[0] = 1;
    // dis[0] = 0;
    // q.push(0);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (long long i = head[u]; i; i = e[i].nex) {
            long long v = e[i].to, w = e[i].cost;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                // if (cnt[v] > n) return 0;
                if (cnt[v] >= n) return 0;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> ml >> md;

    for (int i = 1; i <= ml; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        if (u > v) swap(u, v);
        // u < v, x[v] - x[u] <= w
        add_edge(u, v, w);
    }

    for (int i = 1; i <= md; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        // x[v] - x[u] >= w -> x[u] - x[v] <= -w
        add_edge(v, u, -w);
    }

    // x[u] <= x[v] -> x[u] - x[v] <= 0
    for (int i = 1; i < n; i++) {
        add_edge(i + 1, i, 0);
    }

    // 加上超级源点的解应该是正确的，但是这道题是求x[n] - x[1]的距离，所以还是以1为参考结点
    // for (int i = 1; i <= n; i++) {
    //     add_edge(0, i, 0);
    // }

    if (spfa()) {
        if (dis[n] == (long long)1e18) {
            cout << "-2\n";
        } else {
            cout << dis[n] << '\n';
        }

        // for (int i = 0; i <= n; i++) {
        //     debug(i, dis[i]);
        // }

    } else {
        cout << "-1\n";
    }

    return 0;
}