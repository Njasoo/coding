#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    int new_a = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            if (a == 0) {
                if (b == 0) {
                    if (new_a == 0) {
                        ans++;
                    } else {
                        new_a--;
                    }
                } else {
                    b--;
                    new_a++;
                }
            } else {
                a--;
            }
        } else {
            if (b == 0) {
                ans += 2;
            } else {
                b--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}