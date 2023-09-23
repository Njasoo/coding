#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

int activated_time[405];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= 400; i++) {
        activated_time[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        int d, s;
        cin >> d >> s;
        activated_time[d] = min(activated_time[d], d - 1 + s);
    }
    int ans = 0;
    for (int k = 1; k <= 400; k++) {
        bool flag = 1;
        for (int i = k - 1; i >= 1; i--) {
            if (2 * k - 1 - i >= activated_time[i]) {
                flag = 0;
                break;
            }
        }
        if (!flag) break;
        ans = max(ans, k);
    }
    cout << ans << '\n';
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