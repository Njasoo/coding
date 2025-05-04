#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 1e5 + 5;
int up[N][21], d[N], n, m, dep[N], u[N], v[N];
vector<int> adj[N];

void dfs(int x) {
    for (int y : adj[x]) {
        if (y == up[x][0]) {
            continue;
        }
        up[y][0] = x;
        dep[y] = dep[x] + 1;
        for (int j = 1; j < 21; j++) {
            up[y][j] = up[up[y][j - 1]][j - 1];
        }
        dfs(y);
    }
}

int LCA(int a, int b) {
    if (dep[b] > dep[a]) {
        swap(a, b);
    }
    int k = dep[a] - dep[b];
    for (int j = 0; j < 21; j++) {
        if (k >> j & 1) {
            a = up[a][j];
        }
    }
    if (a == b) {
        return a;
    }
    for (int j = 20; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void dfs2(int x) {
    for (int y : adj[x]) {
        if (y == up[x][0]) {
            continue;
        }
        dfs2(y);
        d[x] += d[y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    dfs(1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++, d[b]++;
        int lca = LCA(a, b);
        d[lca]--, d[up[lca][0]]--;
    }
    dfs2(1);
    int ans = -1;
    for (int i = n - 1; i >= 1; i--) {
        if (d[u[i]] == m && d[v[i]] == m) {
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}