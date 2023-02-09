#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
struct Dsu {
    int f[N], siz[N];
    Dsu(int n) {
        for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
    }
    int leader(int x) {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return 0;
        f[y] = x;
        siz[x] += siz[y];
        return 1;
    } 
    int size(int x) { return siz[leader(x)]; }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    Dsu d(n);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        d.merge(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (d.f[i] == i) {
            cnt++;
        }
    }     
    cout << (cnt == 1 ? "Yes" : "No") << '\n';
    return 0;
}