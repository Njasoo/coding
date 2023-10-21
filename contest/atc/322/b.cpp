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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    bool yes1 = 1, yes2 = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            yes1 = 0;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (s[i] != t[m - n + i]) {
            yes2 = 0;
            break;
        }
        
    }
    if (yes1 && yes2) {
        cout << "0";
    } else if (yes1) {
        cout << "1";
    } else if (yes2) {
        cout << "2";
    } else {
        cout << "3";
    }
    cout << '\n';
    return 0;
}