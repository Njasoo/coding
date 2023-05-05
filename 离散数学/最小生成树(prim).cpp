#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 5;
const int M = 2e5 + 5;
long long dis[N];
struct Edge {
    int from, to, nex;
    long long cost;
}e[M << 1];

int head[N];
int idx;
void add_edge(int u, int v, long long w) {
    idx++;
    e[idx].from = u;
    e[idx].to = v;
    e[idx].cost = w;
    e[idx].nex = head[u];
    head[u] = idx;
}

struct node {
    int cost, id;

    bool operator < (const node &x) const {
        return x.cost < cost;
    }
};
priority_queue<node> q;

bool vis[N];
int n, m;
int tot;
long long ans = 0;
bool prim() {
    dis[1] = 0;
    q.push({0, 1});
    while (!q.empty()) {
        auto d = q.top().cost;
        auto u = q.top().id;
        q.pop();
        if (vis[u]) continue;
        printf("add: %c\n", char(u + 'a' - 1));
        vis[u] = 1;
        tot++;
        printf("%d\n", d);
        ans += d;
        for (int i = head[u]; i; i = e[i].nex) {
            int w = e[i].cost;
            int v = e[i].to;
            if (w < dis[v]) {
                dis[v] = w;
                q.push({dis[v], v});
            }
        }
    }
    return tot == n;
}

int main() {
    scanf("%d %d", &n, &m);
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 1; i <= m; i++) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    if (prim()) {
        printf("%lld\n", ans);
    } else {
        printf("orz\n");
    }
    return 0;
}