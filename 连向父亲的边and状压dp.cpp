#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 1e5 + 5;
vector<int> g[N];
int s[N], dp[1 << 20];
// s[i]: 二进制状态表示结点i对应的边被第几条路径经过，结点i对应的边就是结点i指向父节点的边

void dfs(int u, int fa) {
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        s[u] ^= s[v]; // 向上传递状态，经过lca的时候会抵消
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        s[i] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        s[u] ^= 1 << i;
        s[v] ^= 1 << i;
    }
    dfs(1, 0);
    set<int> S;
    for (int i = 1; i <= n; i++) {
        S.insert(s[i]);
    }
    for (int mask = 1; mask < (1 << k); mask++) {
        dp[mask] = k;
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << k); i++) {
        for (auto j : S) {
            dp[i | j] = min(dp[i | j], dp[i] + 1);
        }
    }
    cout << dp[(1 << k) - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}