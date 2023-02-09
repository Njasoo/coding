#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 5;
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
    Dsu dsu(n);   
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }
    int k;
    cin >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (dsu.same(a, b)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}