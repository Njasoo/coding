#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], dp[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, n = 0;
    while (cin >> x) {
        a[++n] = x;
    }   
    int ans = 0;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i - 1;
        int pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (dp[mid] >= a[i]) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        dp[pos + 1] = max(dp[pos + 1], a[i]);
        ans = max(ans, pos + 1);
    }
    cout << ans << '\n';
    memset(dp, 0x3f, sizeof(dp));
    ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = 0, r = i - 1;
        int pos = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (dp[mid] < a[i]) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        dp[pos + 1] = min(dp[pos + 1], a[i]);
        ans = max(ans, pos + 1);
    }
    cout << ans << '\n';
    return 0;
}