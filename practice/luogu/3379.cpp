#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 5e5 + 5;
const int LOG = 19;
int up[N][LOG], depth[N];
vector<int> adj[N];
void init(int u, int fa) {
    for (auto v : adj[u]) {
        if (v == fa) continue;
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        for (int j = 1; j < LOG; j++) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
        init(v, u);
    }
}
int LCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int j = 0; j < LOG; j++) {
        if (diff & (1 << j)) {
            a = up[a][j];
        }
    }
    if (a == b) return a;
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    init(s, 0);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
    return 0;
}