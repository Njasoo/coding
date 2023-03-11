#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void solve() {
    int l, r;
    cin >> l >> r;
    int ans1 = 0, now = l;
    while (now <= r) {
        ans1++;
        now *= 2;
    }
    long long temp = 1 << (ans1 - 1);
    // cerr << "temp: " << temp << endl;
    long long ans2 = r / temp - l + 1;
    // temp *= 3 / 2; // 我屮艸芔茻
    temp = temp * 3 / 2;
    if (temp * l <= r) {
        // cerr << " " << r / temp - l + 1 << endl;
        if (ans1 - 1 > 0)
            ans2 = (ans2 + (ans1 - 1) * (r / temp - l + 1) % MOD) % MOD;
    }
    cout << ans1 << " " << ans2 << '\n';
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