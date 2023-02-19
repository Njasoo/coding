#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long sum[N], ans[N], a[N], b[N], d[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        // 忘记清空了
        memset(d, 0, sizeof(d));
        memset(ans, 0, sizeof(ans));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            sum[i] = sum[i - 1] + b[i];
        }
        for (int i = 1; i <= n; i++) {
            int l = i, r = n;
            int pos = i - 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                // 从 i 到 mid 都能喝够
                if (sum[mid] - sum[i - 1] <= a[i]) {
                    pos = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            d[i]++, d[pos + 1]--;
            ans[pos + 1] += a[i] - (sum[pos] - sum[i - 1]);
        }
        for (int i = 1; i <= n; i++) {
            d[i] += d[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            ans[i] += d[i] * b[i];
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << " \n"[i == n];
        }
    }   
    return 0;
}
