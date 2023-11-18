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
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        bool ok = true;
        for (int i = 0; i < n - 1; i++) {
            ok &= (s[i] != s[i + 1]);
        }
        if (ok) {
            cout << "YES\n";
            continue;
        }
        ok = true;
        for (int i = 0; i < (int) t.size() - 1; i++) {
            ok &= (t[i] != t[i + 1]);
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < (int) s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                ok &= (s[i] != t[0] && s[i + 1] != t.back());
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}