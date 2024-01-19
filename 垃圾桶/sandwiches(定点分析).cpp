#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "d:/coding/debug.h"
#else
#define debug(...) 114514;
#endif

const int N = 3e5 + 5;
long long cntl[N], cntr[N];
long long a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cntr[a[i]]++;
    }   
    cntl[a[1]]++;
    cntr[a[1]]--;
    long long tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += cntl[i] * cntr[i];
    }
    debug(tot);
    long long ans = 0;
    for (int i = 2; i < n; i++) {
        ans += tot - cntl[a[i]] * cntr[a[i]];
        tot -= cntl[a[i]] * cntr[a[i]];
        tot += (cntl[a[i]] + 1) * (cntr[a[i]] - 1);
        cntl[a[i]]++;
        cntr[a[i]]--;
    }
    cout << ans << '\n';
    return 0;
}