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

const int N = 1005;
struct Node {
    double l, r;
} p[N];

bool cmp(Node i, Node j) {
    return i.r < j.r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k = 0;
    while (1) {
        int n, d;
        cin >> n >> d;
        if (n == 0 && d == 0) break;
        bool ok = 1;
        if (d < 0) {
            ok = 0;
        }
        for (int i = 1; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            if (y > d || y < 0) {
                ok = 0;
                continue;
            }
            double r = sqrt(1.0 * d * d - y * y);
            p[i].l = x - r;
            p[i].r = x + r;
        }
        cout << "Case " << ++k << ": ";
        if (!ok) {
            cout << "-1\n";
            continue;
        }
        sort(p + 1, p + 1 + n, cmp);
        int ans = 0;
        int i = 1;
        while (i <= n) {
            // debug(i);
            int j = i + 1;
            while (j <= n && p[i].r >= p[j].l) {
                j++;
                // debug(j);
            }
            ans++;
            i = j;
        }
        cout << ans << '\n';
    }       
    return 0;
}