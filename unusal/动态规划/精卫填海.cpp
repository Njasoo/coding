#include <bits/stdc++.h>

using namespace std;

int dp[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, n, C;
    cin >> V >> n >> C;
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int k, m;
        cin >> k >> m;
        for (int j = C; j >= m; j--) {
            dp[j] = max(dp[j], dp[j - m] + k);
            if (dp[j] >= V) {
                ans = max(ans, C - j);
            }
        }
    }      
    if (ans == -1) {
        cout << "Impossible" << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}