#include <cstdio>
#include <vector>

using namespace std;

vector<int> p[500005];
int vis[500005], parent[500005], depth[500005];

void dfs(int u) {
    vis[u] = 1;
    for (int u_son : p[u]) {
        if (vis[u_son] == 0) {
            parent[u_son] = u;
            depth[u_son] = depth[u] + 1;
            dfs(u_son);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    while (depth[a] > depth[b]) {
        a = parent[a];
    }
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main() {
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 1; i <= n - 1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[x].push_back(y);
        p[y].push_back(x);
    }
    dfs(s);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", LCA(a, b));
    }
    return 0;
}