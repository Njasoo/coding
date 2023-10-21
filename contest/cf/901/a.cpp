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
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, n;
        cin >> a >> b >> n;
        long long ans = b;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            ans += min(x, a - 1);
        }
        cout << ans << '\n';
    }   
    return 0;
}