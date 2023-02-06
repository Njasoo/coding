#include <bits/stdc++.h>

using namespace std;

int n, m;
char val[100005];
int ans[100005];
int vis[100005], depth[100005], up[100005][17];
int cntg[100005], cnth[100005];
vector<int> p[100005];

void dfs(int u) {
    vis[u] = 1;
    cntg[u] = cntg[up[u][0]];
    cnth[u] = cnth[up[u][0]];
    if (val[u] == 'G') {
        cntg[u]++;
    } else {
        cnth[u]++;
    }
    for (int v : p[u]) {
        if (!vis[v]) {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for (int j = 1; j < 17; j++) {
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
    for (int j = 16; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;    
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }  
    dfs(1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'G' && cntg[a] + cntg[b] - 2 * cntg[up[LCA(a, b)][0]] - (val[LCA(a, b)] == 'G') > 0) {
            ans[i] = 1;
        } else if (c == 'H' && cnth[a] + cnth[b] - 2 * cnth[up[LCA(a, b)][0]] - (val[LCA(a, b)] == 'H') > 0) {
            ans[i] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}