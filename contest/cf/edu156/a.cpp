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
        int n;
        cin >> n;
        n--;
        int l = 2, r = n - 2;
        while ((l % 3 == 0 || r % 3 == 0) && l < r) {
            l++;
            r--;
        }
        if (l >= r) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << 1 << " " << l << " " << r << '\n';
        }
    }   
    return 0;
}