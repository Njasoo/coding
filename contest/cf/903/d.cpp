#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 2; j * j <= x; j++) {
            while (x % j == 0) {
                x /= j;
                cnt[j]++;
            }
        }
        if (x != 1) {
            cnt[x]++;
        }
    }
    for (auto [_, y] : cnt) {
        if (y % n) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}