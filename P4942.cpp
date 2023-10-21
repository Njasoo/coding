#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

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
    // 2345 = 2 * 1000 + 3 * 100 + 4 * 10 + 5
    int q;
    cin >> q;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll cnt = ((l + r) % 9) * (r - l + 1) * 5 % 9;
        cout << cnt % 9 << '\n';
    }
    return 0;
}