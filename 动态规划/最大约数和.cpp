#include <bits/stdc++.h>

using namespace std;

long long dp[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            long long cnt = 0;
            for (int k = 1; k <= i - 1; k++) {
                if (i % k == 0) {
                    cnt += k;
                }
            }
            dp[j] = max(dp[j], dp[j - i] + cnt);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}