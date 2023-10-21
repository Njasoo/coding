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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;   
    ll l = 0, r = n;
    ll ans = -1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll add = n - mid;
        ll tot = add * (add + 1) / 2;
        if (tot - mid >= m) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}