#include <bits/stdc++.h>
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define pb push_back
#define len(x) int(x.size())
using ll = long long;
using namespace std;

const int N = 1e5 + 5;
ll dp[N][3];
int n, sp[N];
vector<int> adj[N];
vector<pair<int, int>> anss;

// dp[u][0]: 未被改变
// dp[u][1]: 该结点以及其父亲被改变
// dp[u][2]: 该节点的某个儿子改变了自己的父亲，意味着u也被改变了

void dfs(int u, int p = 0) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    dp[u][2] = 0;
    ll cnt_2 = 0;
    ll cnt_mn = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        cnt_2 += dp[v][2];
        cnt_mn += min(dp[v][0], dp[v][2]);
    }
    dp[u][0] += cnt_2;
    dp[u][1] += cnt_mn;
    ll tmp = 1e9;
    int mn_id = 0;
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        // tmp = min(cnt_mn - min(dp[v][0], dp[v][2]) + dp[v][1], tmp);
        if (cnt_mn - min(dp[v][0], dp[v][2]) + dp[v][1] < tmp) {
            tmp = cnt_mn - min(dp[v][0], dp[v][2]) + dp[v][1];
            mn_id = v;
        }
    }
    sp[u] = mn_id;
    // db(u), db(sp[u]), el;
    dp[u][2] = tmp;
    if (adj[u].size() <= 1) {
        dp[u][2] = 1e9;
    }
    // db(u), db(dp[u][0]), db(dp[u][1]), db(dp[u][2]), el;
}

void dfs2(int u, int p, int s) {
    if (s == 0) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs2(v, u, 2);
        }
    } else if (s == 1) {
        anss.push_back({u, p});
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (dp[v][2] < dp[v][0]) {
                dfs2(v, u, 2);
            } else {
                dfs2(v, u, 0);
            }
        }
    } else if (s == 2) {
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (v == sp[u]) {
                dfs2(v, u, 1);
            } else {
                if (dp[v][2] < dp[v][0]) {
                    dfs2(v, u, 2);
                } else {
                    dfs2(v, u, 0);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1);
    if (dp[1][0] < dp[1][2]) {
        dfs2(1, 0, 0);
    } else {
        dfs2(1, 0, 2);
    }
    cout << len(anss) << "\n";
    for (auto x : anss) {
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}