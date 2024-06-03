#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    int x;
    cin >> x;
    int ans = 0, mx = 0;
    for (int i = 1; i < x; i++) {
        if (gcd(x, i) + i > mx) {
            mx = gcd(x, i) + i;
            ans = i;
        }
    }
    cout << ans << '\n';
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