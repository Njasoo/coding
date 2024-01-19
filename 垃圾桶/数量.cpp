#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int MOD = 1e9 + 7;
const int N = 1e3 + 5;
const int MN = 1e3;
long long fac[N], inv_fac[N];

long long power(long long u, long long v) {
    long long res = 1;
    while (v) {
        if (v & 1)
            res = res * u % MOD;
        u = u * u % MOD;
        v >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= MN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MN] = power(fac[MN], MOD - 2);
    for (int i = MN - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

long long C(int n, int k) {
    if (k > n)
        return 0;
    return (fac[n] * inv_fac[k] % MOD) * inv_fac[n - k] % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    init();
    long long ans = 0;
    for (int i = n - k; i <= n; i++) {
        ans += C(n, i) * fac[n - i - 1];
    }
    cout << ans << '\n';
    return 0;
}