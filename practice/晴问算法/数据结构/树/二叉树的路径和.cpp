#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }   
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (u != -1) p[i].push_back(u);
        if (v != -1) p[i].push_back(v);
    }
    vector<int> sum(n);
    sum[0] = w[0];
    int ans = 0;
    function<void(int)> solve = [&](int u) {
        if (p[u].empty()) ans += sum[u];
        for (int v : p[u]) {
            sum[v] = sum[u] + w[v];
            solve(v);
        }
    };
    solve(0);
    cout << ans << '\n';
    return 0;
}