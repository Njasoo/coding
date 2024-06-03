#include <bits/stdc++.h>

using namespace std;

// 1 <= a[1] + a[2] + a[3] + ... + a[m] <= n的序列a个数
// -> a[1] + a[2] + ... + a[m] + a[m + 1] == n的解的个数，再排除a[m + 1] == n的情况

const int MOD = 1e6 + 3;
long long fac[700005], inv_fac[700005];

long long power(long long u, long long v) {
    long long res = 1;
    while (v) {
        if (v & 1) res = res * u % MOD;
        u = u * u % MOD;
        v >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= 700000; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[700000] = power(fac[700000], MOD - 2);
    for (int i = 700000 - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int n, m;
    cin >> n >> m;   
    cout << (((((fac[n + m] * inv_fac[n] % MOD) * inv_fac[m]) % MOD) - 1) % MOD + MOD) % MOD << '\n';
    return 0;
}