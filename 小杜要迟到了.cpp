#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    long long ans1 = 1. * (n - 1) * a;
    long long ans2 = 1. * (k - 1 + n - 1) * b;
    debug(ans1, ans2);
    if (ans1 == ans2) cout << "0";
    else if (ans1 > ans2) cout << '1';
    else cout << "2";
    cout << '\n';
    return 0;
}