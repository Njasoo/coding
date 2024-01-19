#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 1e6 + 5;
long long dp[N][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k = 0;
    int n;
    while (cin >> n) {
        long long ans = -1e18;
        dp[0][0] = dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            dp[i][0] = min({dp[i - 1][0] * a, dp[i - 1][1] * a, a});
            dp[i][1] = max({dp[i - 1][0] * a, dp[i - 1][1] * a, a});
            ans = max(ans, dp[i][1]);
        }
        cout << "Case: #" << ++k << ": The maximum product is " << (ans > 0 ? ans : 0) << ".\n\n";
    }      
    return 0;
}