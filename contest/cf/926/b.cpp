#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if ((n + n - 2) * 2 >= k) {
        cout << (k + 1) / 2 << '\n';
        return;
    }
    long long cnt = (2 * n - 2) * 2;
    k -= cnt;
    cout << k + 2 * n - 2 << '\n';
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