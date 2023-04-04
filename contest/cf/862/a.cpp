#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt ^= a;
    }
    if (n % 2) {
        cout << cnt << '\n';
    } else {
        cout << (cnt == 0 ? 0 : -1) << '\n';
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