#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

const int N = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll a[N], sum[N];

ll power(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v & 1)
            res = res * u % MOD;
        u = u * u % MOD;
        v /= 2;
    }
    return res;
}

ll inv(ll x) { return power(x, MOD - 2); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i];
        sum[i] %= MOD;
    }
    ll diff = 0;
    for (int i = 1; i <= n; i++) {
        diff += a[i] * (i - 1) - sum[i - 1];
        diff %= MOD;
    }
    diff *= 2;
    diff %= MOD;
    cout << diff * inv(n) % MOD << "\n";
    return 0;
}