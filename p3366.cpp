#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

const int N = 5e3 + 5;
int n, m;
vector<pair<int, int>> g[N];
bool vis[N];
long long ans = 0;

bool prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});
    int tot = 0;
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        tot++;
        ans += d;
        for (auto [v, w] : g[u]) {
            q.push({w, v});
        }
    }
    return tot == n;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    if (prim()) {
        cout << ans << '\n';
    } else {
        cout << "orz\n";
    }
    return 0;
}