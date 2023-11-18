#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const int MN = 1e5;
const int MOD = 1e9 + 7;
int cnt[N];
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
    return (fac[n] * inv_fac[k] % MOD) * inv_fac[n - k] % MOD;
}

int main() {
    int n;
    cin >> n;
    int mx_a = 0;
    init();
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        mx_a = max(mx_a, a);
    }
    long long ans = 0;
    for (int i = 1; i <= mx_a; i++) {
        if (cnt[i] == 0)
            continue;
        for (int j = 1; j <= i / 2; j++) {
            if (j == i - j) {
                ans = (ans + C(cnt[i], 2) * C(cnt[j], 2) % MOD) % MOD;
            } else {
                ans = (ans + (C(cnt[i], 2) * cnt[j] % MOD) * cnt[i - j]) % MOD;
            }
        }
        // cout << "temp=" << temp << endl;
        // cout << "C(cnt[i],2)=" << C(cnt[i], 2) << endl;
    }
    cout << ans << endl;
    return 0;
}