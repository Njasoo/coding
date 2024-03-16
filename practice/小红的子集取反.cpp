#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot += abs(a[i]);
    }
    const int N = 1e5, ofs = 5e4;
    vector<array<int, N>> dp(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = 1e9;
        }
    }
    if (a[0] == 0) {
        dp[0][0 + ofs] = 0;
    } else {
        dp[0][a[0] + ofs] = 0;
        dp[0][-a[0] + ofs] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = -40000; j <= 40000; j++) {
            dp[i][j + ofs] = min(dp[i - 1][j - a[i] + ofs], dp[i - 1][j + a[i] + ofs] + 1);
        }
    }
    if (dp[n - 1][ofs] == 1e9) {
        cout << "-1\n";
    } else {
        cout << dp[n - 1][ofs] << '\n';
    }
    return 0;
}