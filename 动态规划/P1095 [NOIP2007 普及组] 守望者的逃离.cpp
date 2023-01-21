#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, s, t;
    cin >> m >> s >> t;
    vector<int> dp(t + 1, 0);
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            dp[i] = dp[i - 1] + 60;
            m -= 10;
        } else {
            dp[i] = dp[i - 1];
            m += 4;
        }
    }   
    for (int i = 1; i <= t; i++) {
        dp[i] = max(dp[i], dp[i - 1] + 17);
        if (dp[i] >= s) {
            cout << "Yes" << '\n';
            cout << i << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    cout << dp[t] << '\n';
    return 0;
}