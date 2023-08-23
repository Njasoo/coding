#include <bits/stdc++.h>

using namespace std;

// adding edges from u to v, the weight of the edge should be greater than the length of the path from u to v
// or we will get another minimum spanning tree

const int MOD = 998244353;

struct DSU {
    vector<int> f, siz;

    DSU(int n) : f(n), siz(n, 1) { iota(f.begin(), f.end(), 0); }

    int root(int x) { return x == f[x] ? x : f[x] = root(f[x]); }

    bool same(int x, int y) { return root(x) == root(y); }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        f[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) { return siz[root(x)]; }
};

long long power(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, S;
    cin >> n >> S;
    vector<array<int, 3>> e(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        e[i] = {w, u, v};
    }
    sort(e.begin(), e.end());
    long long ans = 1;
    DSU dsu(n);
    for (auto [w, u, v] : e) {
        long long cnt = 1LL * dsu.size(u) * dsu.size(v) - 1;
        ans = ans * power(S - w + 1, cnt) % MOD;
        dsu.unite(u, v);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}