#include <bits/stdc++.h>

using namespace std;

int len[1505][1505], d[1505];
int n, m;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        len[u][v] = max(len[u][v], w);
    }
    memset(d, -1, sizeof(d));
    d[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (len[u][i] && d[i] < d[u] + len[u][i]) {
                d[i] = d[u] + len[u][i];
                q.push(i);
            }
        }
    }
    cout << d[n] << '\n';
    return 0;
}