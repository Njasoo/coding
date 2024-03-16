#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> f, siz;

    DSU(int n) : f(n), siz(n, 1) {
        iota(f.begin(), f.end(), 0);
    }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool unite(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;
        f[y] = x;
        siz[x] += siz[y];
        return true;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    int size(int x) {
        return siz[leader(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<array<int, 3>> e(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            e[i] = {w, u, v};
        }
        sort(e.begin(), e.end(), greater());
        vector<vector<int>> adj(n);
        int ans = 1e9;
        int U, V;
        DSU dsu(n);
        for (auto [w, u, v] : e) {
            if (!dsu.unite(u, v)) {
                ans = w;
                U = u;
                V = v;
            } else {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<int> path;
        auto dfs = [&](auto self, int u, int fa) -> bool {
            if (u == V) {
                path.push_back(u);
                return true;
            }
            for (int v : adj[u]) {
                if (v == fa) continue;
                if (self(self, v, u)) {
                    path.push_back(u);
                    return true;
                }
            }
            return false;
        };
        dfs(dfs, U, -1);
        cout << ans << " " << path.size() << '\n';
        for (int x : path) {
            cout << x + 1 << " \n"[x == path.back()];
        }
    }
    return 0;
}