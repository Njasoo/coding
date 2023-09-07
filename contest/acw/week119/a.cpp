#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

void solve() {
    string s;
    cin >> s;
    cout << s[0];
    for (int i = 1; i < (int) s.size() - 1; i += 2) {
        cout << s[i];
    }
    cout << s.back() << '\n';
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