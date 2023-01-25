#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int a[N];
vector<int> p[N];
int n, m;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (a[u] != a[v]) {
            if (a[u] > a[v]) p[v].push_back(u);
            else p[u].push_back(v);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int u = i;
        while (!p[u].empty()) {
            for (int v : p[u]) {
                u = v;
            }
        }
        if (ans && u != ans) {
            ans = 0;
            break;
        }
        ans = u;
    }
    if (!ans) {
        cout << "Non\n";
    } else {
        cout << "Oui, j'ai trouve la solution.\n";
        cout << ans << '\n';
    }
    return 0;
}