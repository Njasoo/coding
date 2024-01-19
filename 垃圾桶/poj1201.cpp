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

// 前缀和 + 差分约束
// sum[b] - sum[a - 1] >= c -> sum[a - 1] - sum[b] <= -c
// sum[i] >= sum[i - 1] -> sum[i - 1] - sum[i] <= 0
// sum[i] - sum[i - 1] <= 1
const int N = 5e4 + 5;
const int M = 2e5 + 5;
long long dis[N];
struct Edge {
    long long to, cost, nex;
} e[M];
bool vis[N];
int head[N], idx;

void add_edge(int u, int v, long long w) {
    idx++;
    e[idx].to = v;
    e[idx].cost = w;
    e[idx].nex = head[u];
    head[u] = idx;
}

void spfa() {
    for (int i = 0; i <= 50001; i++) {
        dis[i] = -1e18;
    }
    memset(vis, 0, sizeof vis);
    dis[0] = 0;
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nex) {
            long long v = e[i].to, w = e[i].cost;
            if (dis[v] < dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        a++, b++;
        // add_edge(b, a - 1, -c);
        add_edge(a - 1, b, c);
    }
    // 0已经是其中一个结点，所以不作为超级源点了
    for (int i = 1; i <= 50001; i++) {
        // add_edge(i, i - 1, 0); // sum[i - 1] - sum[i] <= 0
        add_edge(i - 1, i, 0); // sum[i] - sum[i - 1] >= 0
        // add_edge(i - 1, i, 1); // sum[i] - sum[i - 1] <= 1
        add_edge(i, i - 1, -1); // sum[i - 1] - sum[i] >= -1
    }
    spfa();
    // for (int i = 1; i <= 100; i++) {
    //     debug(i, dis[i]);
    // }
    cout << dis[50001] - dis[0] << '\n';
    return 0;
}