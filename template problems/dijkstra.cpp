#include <bits/stdc++.h>

using namespace std;

// dijkstra use greedy strategy
// for each point we haven't visited, we choose the point which has the shortest dis from the point

const int inf = 2147483647;
int n, m, s, cnt = 0;
int dis[100005], head[100005], vis[100005];
struct Edge {
    int from, to, cost, prev;
}e[5000005];
struct node {
    int w, now;

    bool operator < (const node& x) const {
        return w > x.w;
    }
};
priority_queue<node> q;

void add(int from, int to, int cost) {
    e[++cnt].from = from;
    e[cnt].to = to;
    e[cnt].cost = cost;
    e[cnt].prev = head[from]; // prev == previous edge
    head[from] = cnt; // store the previous edge for next edge to update
}

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
    }
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        int u = x.now;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i != 0; i = e[i].prev) {
            int v = e[i].to;
            if (dis[u] + e[i].cost < dis[v]) {
                dis[v] = dis[u] + e[i].cost;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }      
    dijkstra();
    for (int i = 1; i <= n; i++) {
        cout << dis[i] << " \n"[i == n];
    }
    return 0;
}