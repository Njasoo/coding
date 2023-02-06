#include <bits/stdc++.h>

using namespace std;

int f[10005];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    iota(f + 1, f + 1 + n, 1);
    for (int i = 0; i < m; i++) {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1) {
            f[find(x)] = find(y);
        } else {
            cout << (find(x) == find(y) ? "Y" : "N") << '\n';
        }
    }
    return 0;
}