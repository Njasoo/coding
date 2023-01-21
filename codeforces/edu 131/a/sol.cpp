#include <bits/stdc++.h>

using namespace std;

void solve() {
    int f[2][2];
    int cnt = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> f[i][j];
            cnt += f[i][j];
        }
    }
    if (cnt == 0) {
        cout << 0 << '\n';
        return;
    } else if (cnt == 4) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}