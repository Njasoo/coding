#include <bits/stdc++.h>

using namespace std;

int f[5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    f[1][1] = 1, f[1][4] = 1, f[2][2] = 1, f[2][3] = 1;
    f[3][2] = 1, f[3][3] = 1, f[4][1] = 1, f[4][4] = 1;
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << f[(i - 1) % 4 + 1][(j - 1) % 4 + 1] << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}