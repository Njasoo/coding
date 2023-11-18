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
        string s;
        cin >> s;
        if (n % 2) {
            cout << "-1\n";
            continue;
        }
        int l = 0, r = n - 1;
        vector<int> ans;
        int cnt = 0;
        while (l < r && cnt < 300) {
            if (s[l] != s[r]) {
                l++, r--;
                continue;
            }
            if (s[r] == '0') {
                s.insert(r + 1, "01");
                ans.push_back(r + 1);
                r += 2;
                cnt++;
            }
            if (s[l] == '1') {
                s.insert(l, "01");
                ans.push_back(l);
                r += 2; 
                cnt++;
            }
        }
        if (l < r) {
            cout << "-1\n";
            continue;
        }
        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}