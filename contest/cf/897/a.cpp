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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            b[a[i].second] = n - i;
        }
        for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n - 1];
        }
    }      
    return 0;
}