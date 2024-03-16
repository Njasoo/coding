#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

const int N = 3e5 + 5, MOD = 998244353;
vector<int> g[N];
long long dp[N][3];

void add(long long& u, long long v) {
    if (v >= MOD) v -= MOD;
    u += v;
    if (u >= MOD) u -= MOD;
}

void mul(long long& u, long long v) {
    if (v >= MOD) v -= MOD;
    u = (u * v) % MOD;
}

void dfs(int u, int fa) {
    dp[u][0] = 1, dp[u][1] = 1;
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        mul(dp[u][1], dp[v][1] + dp[v][0]);
        add(dp[u][2], dp[v][1] + dp[v][2]);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        dp[i][0] = dp[i][1] = dp[i][2] = 0;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    dfs(1, 0);
    cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD << '\n';
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