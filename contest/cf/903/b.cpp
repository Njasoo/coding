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
        int64_t a[3];
        cin >> a[0] >> a[1] >> a[2];
        bool flag = 0;
        if (a[0] == a[1] && a[1] == a[2]) {
            flag = 1;
        }
        int64_t sum = a[0] + a[1] + a[2];
        sort(a, a + 3);
        if (sum % 4 == 0) {
            int each = sum / 4;
            if (a[0] == each && a[1] == each && a[2] == each + each) {
                flag = 1;
            }
        }
        if (sum % 5 == 0) {
            int each = sum / 5;
            if (a[0] == each && a[1] == 2 * each && a[2] == 2 * each) {
                flag = 1;
            } else if (a[0] == each && a[1] == each && a[2] == 3 * each) {
                flag = 1;
            }
        }
        if (sum % 6 == 0) {
            int each = sum / 5;
            if (a[0] == each && a[1] == each && a[2] == 4 * each) {
                flag = 1;
            } else if (a[0] == 2 * each && a[1] == 2 * each && a[2] == 2 * each) {
                flag = 1;
            } else if (a[0] == each && a[1] == 2 * each && a[2] == 3 * each) {
                flag = 1;
            }
        }
        cout << (flag ? "YES" : "NO") << '\n';
    }   
    return 0;
}