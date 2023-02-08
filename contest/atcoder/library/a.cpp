#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int MN = 200000;
int f[MN + 5];
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
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) f[i] = i;
    while (q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << (int) same(u, v) << '\n';
        } else {
            merge(u, v);
        }
    }
    return 0;
}