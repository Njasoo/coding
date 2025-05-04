#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// dp[i]: 到第i层的时间期望
// dp[i] = (dp[i - 1] + 1) + p[i] * dp[i] =>  dp[i] = (dp[i - 1] + 1) / (1 - p[i])
// dp[0] = 0;
const int N = 1e5 + 5;
const ll MOD = 998244353;

ll power(ll u, ll v) {
    ll res = 1;
    while (v) {
        if (v % 2) res = res * u % MOD;
        u = u * u % MOD;
        v /= 2;
    }
    return res;
}

ll inv(ll x) {
    return power(x, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    ll dp = 0;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        dp = (dp + 1) * inv((y - x) * inv(y) % MOD) % MOD;
    }
    cout << dp << '\n';
    return 0;
}