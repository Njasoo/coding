#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
const int MN = 1000;
const int MOD = (int) 1e9 + 7;
long long fac[N], inv_fac[N];
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
    for (int i = 1; i <= MN; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv_fac[MN] = power(fac[MN], MOD - 2);
    for (int i = MN - 1; i >= 0; i--) {
        inv_fac[i] = inv_fac[i + 1] * (i + 1) % MOD;
    }
}
long long C(int n, int m) {
    if (m > n) return 0;
    return (fac[n] * inv_fac[m] % MOD) * inv_fac[n - m] % MOD;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n, m, k;
    cin >> n >> m >> k;
    // C(n - 1, 2k) * C(m - 1, 2k)
    // 边长为n, 有n + 1行, 行列各选2k行, 相乘即是结果
    // cerr << C(3, 1) << endl;
    cout << C(n - 1, 2 * k) * C(m - 1, 2 * k) % MOD << '\n';
    return 0;
}