#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
const int N = 105;
int a[N], dp[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0x3f3f3f3f;
    for (int k = 1; k <= n; k++) {
        // 1 ~ k的最长上升子序列
        int mx = 1;
        for (int i = 1; i <= k; i++) {
            dp[i] = 1;
            for (int j = 1; j < i; j++) {
                if (a[j] < a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        // 为什么不是从k + 1开始？ 因为无法保证t[k] > t[k + 1]
        // 好像重叠了也无所谓，因为如果重叠了, a[k]也是不需要出列的人
        int cnt = k - mx; // 要出来的人
        mx = 1;
        for (int i = k; i <= n; i++) {
            dp[i] = 1;
            for (int j = k; j < i; j++) {
                if (a[j] > a[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }
        cnt += n - k + 1 - mx;
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}