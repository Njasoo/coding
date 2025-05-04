ll power(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v & 1) {
            res = res * u % MOD;
        }
        u = u * u % MOD;
        v >>= 1;
    }
    return res;
}