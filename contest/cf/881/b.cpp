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

const int N = 2e5 + 5;
ll a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        ll ans1 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans1 += llabs(a[i]);
        }
        int op1 = 0, op2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] >= 0) continue;
            int j = i;
            while (j <= n && a[j] <= 0) {
                j++;
            }
            op1++;
            i = j - 1;
        }
        debug(op1);
        for (int i = 1; i <= n; i++) {
            if (a[i] <= 0) continue;
            int j = i;
            while (j <= n && a[j] >= 0) {
                j++;
            }
            op2++;
            i = j - 1;
        }
        op2++;
        cout << ans1 << " " << min(op1, op2) << '\n';
    }   
    return 0;
}