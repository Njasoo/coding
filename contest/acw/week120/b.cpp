#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int len = std::log10(n) + 1;
    // 0表示4， 1表示7
    int ans = 0;
    for (int now_len = 1; now_len <= len; now_len++) {
        for (int mask = 0; mask < (1 << now_len); mask++) {
            int cnt = 0;
            for (int i = 0; i < now_len; i++) {
                if (mask >> i & 1) {
                    cnt = cnt * 10 + 7;
                } else {
                    cnt = cnt * 10 + 4;
                }
            }
            if (cnt <= n) {
                ans++;
            }
        }
    }
    std::cout << ans << '\n';
    return 0;
}