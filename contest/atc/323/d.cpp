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
    map<long long, int> hs;
    for (int i = 1; i <= n; i++) {
        long long s;
        int c;
        cin >> s >> c;
        hs[s] = c;
    }   
    while (1) {
        bool flag = 1;
        for (auto [x, y] : hs) {
            if (y != 1) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << hs.size() << '\n';
            break;
        }
        map<long long, int> new_hs;
        for (auto [x, y] : hs) {
            int cnt = 1;
            while (y) {
                if (y & 1) {
                    new_hs[x * cnt]++;
                }
                cnt <<= 1;
                y >>= 1;
            }
        }
        hs.swap(new_hs);
    }
    return 0;
}