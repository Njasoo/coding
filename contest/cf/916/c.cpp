#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        int a[n + 5], b[n + 5], sum[n + 5] {}, pre_max[n + 5] {};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            pre_max[i] = max(pre_max[i - 1], b[i]);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (k < i) break;
            ans = max(ans, sum[i] + (k - i) * pre_max[i]);
        }
        cout << ans << '\n';
    }   
    return 0;
}