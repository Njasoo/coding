#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 6005;
vector<int> g[N];
int n;
int r[N], f[N], dp[N][2];

void dfs(int u) {
    if (g[u].empty()) {
        dp[u][0] = 0;
        dp[u][1] = r[u];
        return;
    }
    for (int v : g[u]) {
        dfs(v);
    }
    for (int v : g[u]) {
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    dp[u][1] += r[u];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        f[l] = k;
        g[k].push_back(l); // 直接上司连向职员
    }
    int s = -1;
    for (int i = 1; i <= n; i++) {
        if (f[i] == 0) {
            s = i;
            break;
        }
    }
    dfs(s);
    // db(dp[3][0]);
    // db(dp[4][0]);
    cout << max(dp[s][0], dp[s][1]) << '\n';
    return 0;
}