#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    const int MOD = 1e9 + 7;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<array<int, 2>> dp(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        dp[u][1] = dp[u][0] = 1;
        for (int v : adj[u]) {
            if (v == fa) continue;
            self(self, v, u);
            dp[u][1] = 1LL * dp[u][1] * (dp[v][1] + dp[v][0]) % MOD;
            dp[u][0] = 1LL * dp[u][0] * dp[v][1] % MOD;
        }
    };
    dfs(dfs, 0, -1);
    cout << (dp[0][0] + dp[0][1]) % MOD << '\n';
    return 0;
}