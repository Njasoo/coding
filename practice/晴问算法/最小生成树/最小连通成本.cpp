#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
struct Edge {
    int from, to, cost;
};
vector<Edge> e;
int f[N], siz[N];
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
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        f[i] = i;
    }   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if (cost) e.push_back({i, j, cost});
        }    }
    sort(e.begin(), e.end(), [&](Edge i, Edge j) {
        return i.cost < j.cost;
    });
    int u;
    cin >> u;
    for (int i = 2; i <= k; i++) {
        int v;
        cin >> v;
        merge(u, v);
    }    
    int ans = 0;
    for (int i = 0; i < e.size(); i++) {
        if (merge(e[i].from, e[i].to)) {
            ans += e[i].cost;
        }
    }
    cout << ans << '\n';
    return 0;
}