#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long INF = 0x3f3f3f3f3f3f3f3f;
long long a[N], dp1[N], dp2[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp1[1] = a[1];
    dp2[n] = a[n];
    for (int i = 2; i <= n; i++) dp1[i] = max(dp1[i - 1] + a[i], a[i]);
    for (int i = 2; i <= n; i++) dp1[i] = max(dp1[i], dp1[i - 1]);
    for (int i = n - 1; i >= 1; i--) dp2[i] = max(dp2[i + 1] + a[i], a[i]);
    for (int i = n - 1; i >= 1; i--) dp2[i] = max(dp2[i], dp2[i + 1]);
    long long ans = -INF; // 坑点
    for (int i = 2; i < n; i++) ans = max(ans, dp1[i - 1] + dp2[i + 1]); // 枚举中间点
    cout << ans << '\n';
    return 0;
}