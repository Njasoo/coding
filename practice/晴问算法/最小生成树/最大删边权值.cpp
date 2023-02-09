#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
struct Edge {
    int from, to, cost;
};
int f[N], siz[N];
vector<Edge> e;
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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        f[i] = i;
    }   
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e.push_back({u, v, w});
        ans += w;
    }
    sort(e.begin(), e.end(), [&](Edge i, Edge j) {
        return i.cost < j.cost;
    });
    for (int i = 0; i < m; i++) {
        if (merge(e[i].from, e[i].to)) {
            ans -= e[i].cost;
        }
    }
    bool flag = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (f[i] == i) cnt++;
    }
    cout << (cnt == 1 ? ans : -1) << '\n';
    return 0;
}