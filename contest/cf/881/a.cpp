#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define vt vector
#define pb push_back
#define sz(x) (int) x.size()
#define p_queue priority_queue
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

ll a[55], sum[55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        ll ans = 0;
        for (int k = 1; k <= n / 2; k++) {
            ans = max(ans, sum[n] - sum[n - k] - sum[k]);
        }
        cout << ans << '\n';
    }   
    return 0;
}