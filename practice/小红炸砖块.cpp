#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> f(n, vector<bool>(m, true));
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        f[x][y] = false;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << (f[i][j] ? '*' : '.');
        }
        cout << '\n';
    }
    return 0;
}