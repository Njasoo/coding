#include <bits/stdc++.h>

using namespace std;

/*
深度, 记录深度最深的结点+1
宽度, 记录同一深度数量最多的那一个
距离, 孩子到父亲算1, 反之算2
*/

const int N = 105;
const int LOG = 8;
int n, vis[N];
int cnt_d[N], max_depth = 0, width = 0;
int up[N][LOG];
int depth[N];
vector<int> p[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : p[u]) {
        if (!vis[v]) {
            up[v][0] = u;
            depth[v] = depth[u] + 1;
            max_depth = max(max_depth, depth[v]);
            cnt_d[depth[v]]++;
            width = max(width, cnt_d[depth[v]]);
            for (int j = 1; j < LOG; j++) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
            dfs(v);
        }
    }
}

int LCA(int a, int b) {
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int j = 0; (1 << j) <= k; j++) {
        if (k & (1 << j)) {
            a = up[a][j];
        }
    }
    if (a == b) {
        return a;
    }
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int query(int x, int y) {
    int lca = LCA(x, y);
    return depth[x] - depth[lca] + (depth[y] - depth[lca]) * 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;   
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    dfs(1);
    int x, y;
    cin >> x >> y;
    cout << max_depth + 1 << '\n';
    cout << width << '\n';
    cout << query(y, x) << '\n';
    return 0;
}