#include <bits/stdc++.h>
using namespace std;
// 贪心? 把子树先拉伸到统一深度
const int N = 5e5 + 5;
vector<pair<int, int>> g[N];
int n, s;
int dp[N]; // dp[i] : 叶子结点到结点i的最长距离
long long ans;
void dfs(int u, int fa) {
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        dp[u] = max(dp[u], dp[v] + w);
    }
    for (auto [v, w] : g[u]) {
        if (v == fa) continue;
        ans += dp[u] - dp[v] - w;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        g[a].push_back({b, t});
        g[b].push_back({a, t});
    }
    dfs(s, 0);
    cout << ans << '\n';
    return 0;
}