#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
int f[N];
struct Edge {
    int from, to, cost;
};
vector<Edge> p;
int leader(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
}
void merge(int x, int y) {
    x = leader(x);
    y = leader(y);
    f[y] = x;
}
bool same(int x, int y) {
    return leader(x) == leader(y);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) f[i] = i;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cost;
            cin >> cost;
            if (cost) {
                p.push_back({i, j, cost});
            }
        }
    }
    sort(p.begin(), p.end(), [&](Edge i, Edge j) {
        return i.cost < j.cost;
    });
    int ans = 0;
    for (int i = 0; i < p.size(); i++) {
        if (same(p[i].from, p[i].to)) continue;
        merge(p[i].from, p[i].to);
        ans += p[i].cost;
    }
    cout << ans << '\n';
    return 0;
}