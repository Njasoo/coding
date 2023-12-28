#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 1e3 + 5;
int t[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
        }
        sort(t + 1, t + 1 + n);
        int ans = 0;
        while (n > 3) {
            ans += min(t[1] + t[2] * 2 + t[n], t[n] + t[n - 1] + t[1] * 2); // 最快的那个人分两趟送两个最慢的或者，最快的两个过去，一个回来，送两个最慢的过去，另一个最快的回来
            n -= 2;
        }
        if (n == 3) { // 剩下三个就让最快的送两趟
            ans += t[1] + t[3];
            n--;
        }
        ans += t[n];
        cout << ans << '\n';
    }   
    return 0;
}