#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << (#x) << "=" << x << " "
#define el cerr << endl
#define ll long long

const int N=1e6+5, MN=1e6;
const ll MOD=1e9+7;
ll fac[N], inv_fac[N];

ll power(ll u, ll v) {
    ll res=1;
    while(v) {
        if(v&1)
            res=res*u%MOD;
        u=u*u%MOD;
        v>>=1;
    }
    return res;
}

void init() {
    fac[0]=1;
    for(int i=1; i<=MN; i++)
        fac[i]=fac[i-1]*i%MOD;
    inv_fac[MN]=power(fac[MN], MOD-2);
    for(int i=MN-1; i>=0; i--)
        inv_fac[i]=inv_fac[i+1]*(i+1)%MOD;
}

ll C(int n, int k) {
    if(n<k)
        return 0;
    return (fac[n]*inv_fac[k]%MOD)*inv_fac[n-k]%MOD;
}

ll sub(ll a, ll b) {
    a-=b;
    if(a<0)
        a+=MOD;
    return a;
}

void solve() {
    int n, m;
    cin >> n >> m;
    if(m/2==0) {
        cout << "1\n";
        return;
    }
    cout << C(n-2, m-1) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int tt;
    cin >> tt;
    while(tt--)
        solve();
    return 0;
}