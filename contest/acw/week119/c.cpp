#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

const int N = 55;
char f[N][N];
int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
vector<int> g[N * N];
int id[N][N];
pair<int, int> id_inv[N * N];
bool finded;
bool vis[N * N];

void dfs(int u, int fa) {
    vis[u] = true;
    for (int v : g[u]) {
        if (v == fa) continue;
        if (vis[v]) {
            finded = true;
            return;
        }
        if (f[id_inv[u].first][id_inv[u].second] != f[id_inv[v].first][id_inv[v].second]) {
            continue;
        }
        dfs(v, u);
    }
    vis[u] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> f[i][j];
        }
    }   
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            id[i][j] = ++cnt;
            id_inv[cnt] = {i, j};
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int dx = dir[k][0], dy = dir[k][1];
                int nx = i + dx, ny = j + dy;
                if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
                g[id[i][j]].push_back(id[nx][ny]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dfs(id[i][j], 0);
            if (finded) break;
        }
    }
    cout << (finded ? "Yes" : "No") << '\n';
    return 0;
}