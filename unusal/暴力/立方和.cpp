#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x;
    cin >> x;
    long long b = 1e4;
    for (long long a = 1; a <= 1e4; a++) {
        while (a * a * a + b * b * b > x) {
            b--;
        }
        if (b > 0 && a * a * a + b * b * b == x) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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