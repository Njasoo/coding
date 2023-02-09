#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (u != -1) p[i].push_back(u);
        if (v != -1) p[i].push_back(v);
    }   
    const int LOG = 7;
    vector<int> depth(n);
    vector<vector<int>> up(n, vector<int>(LOG));
    function<void(int)> init = [&](int u) {
        for (int v : p[u]) {
            depth[v] = depth[u] + 1;
            up[v][0] = u;
            for (int j = 1; j < LOG; j++) {
                up[v][j] = up[up[v][j - 1]][j - 1];
            }
            init(v);
        }
    };
    auto LCA = [&](int a, int b) -> int {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                a = up[a][j];
            }
        }
        if (a == b) return a;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[a][j] != up[b][j]) {
                a = up[a][j];
                b = up[b][j];
            }
        }
        return up[a][0];
    };
    init(0);
    cout << LCA(k1, k2) << '\n';
    return 0;
}