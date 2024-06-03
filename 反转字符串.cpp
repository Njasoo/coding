#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> c(n);
    vector<string> s(n), rs(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        rs[i] = string(s[i].rbegin(), s[i].rend());
    }
    vector<i64> dp(2);
    vector<string> mx(2, "");
    for (int i = 0; i < n; i++) {
        auto g = dp;
        auto new_mx = mx;
        dp.assign(2, 1e18);
        if (s[i] >= mx[0]) {
            new_mx[0] = s[i];
            dp[0] = min(dp[0], g[0]);
        }
        if (s[i] >= mx[1]) {
            new_mx[0] = s[i];
            dp[0] = min(dp[0], g[1]);
        }
        if (rs[i] >= mx[0]) {
            new_mx[1] = rs[i];
            dp[1] = min(dp[1], g[0] + c[i]);
        }
        if (rs[i] >= mx[1]) {
            new_mx[1] = rs[i];
            dp[1] = min(dp[1], g[1] + c[i]);
        }
        mx = new_mx;
        // cerr << "i = " << i << endl;
        // cerr << "dp[0]: " << dp[0] << " "
        //      << "dp[1]: " << dp[1] << endl;
    }
    i64 ans = min(dp[0], dp[1]);
    if (ans == (i64)1e18) {
        cout << "-1\n";
    } else {
        cout << ans << '\n';
    }
    return 0;
}