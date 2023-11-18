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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }
        if (cnt.size() > 2) {
            cout << "NO\n";
            continue;
        }
        if (cnt.size() == 1) {
            cout << "YES\n";
            continue;
        }
        int sz1 = -1, sz2 = -1;
        for (auto [x, y] : cnt) {
            if (sz1 == -1) {
                sz1 = y;
            } else {
                sz2 = y;
            }
        }
        if (abs(int(sz1 - sz2)) <= 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}