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
        string s;
        cin >> s;
        int n = s.size();
        long long pos;
        cin >> pos;
        int which = 0;
        for (int i = 1; i <= n; i++) {
            int len = n - i + 1;
            if (pos <= len) {
                which = i;
                break;
            }
            pos -= len;
        }
        debug(which, pos);
        s = ' ' + s + char('a' - 1);
        int need_to_delete = which - 1;
        debug(need_to_delete);
        string ans = " ";
        for (int i = 1; i <= n; i++) {
            while (ans.size() > 1 && need_to_delete && s[i] < ans.back()) {
                ans.pop_back();
                need_to_delete--;
            }
            ans += s[i];
        }
        debug(need_to_delete, ans);
        cout << ans[pos];
    }   
    return 0;
}