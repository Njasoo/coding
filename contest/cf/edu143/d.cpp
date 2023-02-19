#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MN = 3e5;
const long long MOD = 998244353;
long long w[N], fac[N], inv[N];
long long power(long long u, long long v) {
    long long res = 1;
    while (v) {
        if (v % 2) res = res * u % MOD;
        u = u * u % MOD;
        v /= 2;
    }
    return res;
}
void init() {
    fac[0] = 1;
    for (int i = 1; i <= MN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[MN] = power(fac[MN], MOD - 2);
    for (int i = MN - 1; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}
long long C(int n, int k) {
    return (fac[n] * inv[k] % MOD) * inv[n - k] % MOD;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }   
    long long ans = C(n / 3, n / 6);
    for (int i = 1; i <= n; i += 3) {
        sort(w + i, w + i + 3);
        if (w[i] == w[i + 2]) {
            ans = (ans * 3) % MOD;
        } else if (w[i] == w[i + 1]) {
            ans = (ans * 2) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}