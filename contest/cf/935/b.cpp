#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long a, b, m;
    cin >> a >> b >> m;
    cout << (m + a) / a + (m + b) / b << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}