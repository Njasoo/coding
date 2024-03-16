#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    vector<int> siz(n), f(n);
    auto dfs = [&](auto self, int u, int fa) -> void {
        f[u] = fa;
        bool same = false;
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            self(self, v, u);
            siz[u] += siz[v];
            if (s[u] == s[v]) {
                same = true;
            }
        }
        if (!same) {
            siz[u]++;
        }
    };
    dfs(dfs, 0, -1);
    i64 ans = 0;
    for (int i = 1; i < n; i++) {
        int part1 = siz[i];
        int part2 = siz[0] - siz[i];
        if (s[i] == s[f[i]]) {
            bool same = false;
            for (int v : adj[f[i]]) {
                if (v == f[f[i]] || v == i) {
                    continue;
                }
                if (s[v] == s[f[i]]) {
                    same = true;
                    break;
                }
            }
            if (f[f[i]] != -1) {
                if (s[f[i]] == s[f[f[i]]]) {
                    same = true;
                }
            }
            if (!same) {
                part2++;
            }
        }
        int cnt = abs(part1 - part2);
        ans += cnt;
    }
    cout << ans << '\n';
    return 0;
}