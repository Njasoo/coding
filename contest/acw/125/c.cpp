#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 1e5 + 5;
int f[N]; // 删掉值为i的数能产生的贡献值

int main() {
    int n;
    scanf("%d", &n);   
    int mx = 0, semx = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x > mx) f[x]--; // 删掉这个数甚至会少了一个有价值的数
        else if (x > semx) f[mx]++; // x是出现在mx的后面，如果删掉mx，则mx的贡献值加1
        if (x > mx) semx = mx, mx = x;
        else if (x > semx) semx = x;
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (f[i] > f[ans]) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}