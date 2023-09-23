#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;
    // 重叠的部分抵消, 不重叠的部分互相不影响, 所以贪心策略可行
    long long cntx = n / x - n / lcm(x, y);
    long long cnty = n / y - n / lcm(x, y);
    long long sumx = (n - cntx + 1 + n) * cntx / 2;
    long long sumy = (1 + cnty) * cnty / 2;
    cout << sumx - sumy << '\n';
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