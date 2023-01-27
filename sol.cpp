#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N], b[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n, greater<int>());
        long long ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += a[i + k] / a[i];
        }
        for (int i = 2 * k + 1; i <= n; i++) {
            ans += a[i];
        }
        cout << ans << '\n';
    }       
    return 0;
}