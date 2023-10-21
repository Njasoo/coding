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
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 2; i <= 16; i += 2) {
        if (s[i] != '0') {
            cout << "No\n";
            return 0;
        }
    }   
    cout << "Yes\n";
    return 0;
}