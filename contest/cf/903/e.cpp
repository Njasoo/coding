#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i + a[i] <= n) {
            dp[i + a[i]] = min(dp[i - 1], dp[i + a[i]]);
        }
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}