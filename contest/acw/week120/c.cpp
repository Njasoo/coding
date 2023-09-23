#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s, t;
    std::cin >> s >> t;
    std::map<char, int> cnt;
    for (int i = 0; i < (int) t.size(); i++) {
        cnt[t[i]]++;
    }
    std::vector<bool> matched(s.size());
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (cnt[s[i]] > 0) {
            cnt[s[i]]--;
            matched[i] = true;
            ans1++;
        }
    }
    for (int i = 0; i < (int) s.size(); i++) {
        if (matched[i]) continue;
        if (islower(s[i])) {
            char temp = toupper(s[i]);
            if (cnt[temp] > 0) {
                cnt[temp]--;
                ans2++;
            }
        } else {
            char temp = tolower(s[i]);
            if (cnt[temp] > 0) {
                cnt[temp]--;
                ans2++;
            }
        }
    }
    std::cout << ans1 << " " << ans2 << "\n";
    return 0;
}