#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

void solve() {
    int l, r;
    cin >> l >> r;
    if (r / 2 * 2 >= l && r / 2 != 1) {
        cout << r / 2 << " " << r / 2 << '\n';
        return;
    }
    if ((l + 1) / 2 * 2 <= r && (l + 1) / 2 != 1) {
        cout << (l + 1) / 2 << " " << (l + 1) / 2 << '\n';
        return;
    }
    // 剩下的情况就是l == r的情况, 也就是要找a + b == l, gcd(a, b) != 1的a和b
    // gcd(a, b) == gcd(a, l - a) == gcd(a, l)
    for (int i = 2; i * i <= l; i++) {
        if (l % i == 0) {
            cout << i << " " << l - i << '\n';
            return;
        }
    }
    cout << "-1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}