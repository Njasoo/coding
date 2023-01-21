#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5, M = 2e6 + 5, MOD = 100003;
int depth[N], vis[N], cnt[N];
vector<int> p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
    queue<int> q;
    depth[1] = 0, vis[1] = 1, cnt[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : p[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
            if (depth[v] == depth[u] + 1) {
                cnt[v] = (cnt[v] + cnt[u]) % MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] << '\n';
    }
    return 0;
}