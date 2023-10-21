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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = s.find("ABC");
    if (pos == string::npos) cout << "-1\n";
    else cout << pos + 1 << '\n';
    return 0;
}