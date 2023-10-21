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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        if (x.find(s) != string::npos) {
            cout << "0\n";
            continue;
        }
        int cnt = 0;
        bool flag = 0;
        while (x.size() < 1000) {
            x += x;
            cnt++;
            if (x.find(s) != string::npos) {
                flag = 1;
                break;
            }
        }
        if (flag) cout << cnt << '\n';
        else cout << "-1\n";
    }   
    return 0;
}