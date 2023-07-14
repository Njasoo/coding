#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int c[N], u[N], in[N], out[N];
vector<pair<int, int>> g[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        // c[i] -= u[i];
        if (c[i] > 0) {
            q.push(i);
        }
    }      
    for (int i = 1; i <= m; i++) {
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        g[uu].push_back({vv, ww});
        in[vv]++;
        out[uu]++;
    }
    while (!q.empty()) {
        int uu = q.front();
        q.pop();
        for (auto [vv, ww] : g[uu]) {
            in[vv]--;
            if (c[uu] > 0) {
                c[vv] += ww * c[uu];
            }
            if (in[vv] == 0) {
                c[vv] -= u[vv];
                q.push(vv);
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] > 0 && out[i] == 0) {
            cout << i << " " << c[i] << '\n';
            flag = 1;
        }
    }
    if (!flag) {
        cout << "NULL\n";
    }
    return 0;
}