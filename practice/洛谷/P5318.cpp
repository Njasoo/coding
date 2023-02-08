#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 5;
vector<int> p[N];
vector<int> ans;
bool vis[N];
int n, m;
void dfs(int u) {
    vis[u] = 1;
    ans.push_back(u);
    for (int v : p[u]) {
        if (vis[v]) continue;
        dfs(v);
    }
}
void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        ans.push_back(u);
        for (int v : p[u]) {
            q.push(v);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        p[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        sort(p[i].begin(), p[i].end());
    }
    dfs(1);
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
    memset(vis, 0, sizeof(vis));
    ans.clear();
    bfs();
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}