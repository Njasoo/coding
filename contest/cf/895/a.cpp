#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

void solve() {
    double a, b, c;
    cin >> a >> b >> c;
    if (b > a) swap(a, b);
    double equal = (a + b) / 2;
    double need_to_scoop = a - equal;
    cout << (int) ceil(need_to_scoop / c) << '\n';
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