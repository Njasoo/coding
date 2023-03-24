#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MN=100000,N=100005;
const ll M=1e9+7;
ll fac[N],inv[N];
ll po(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%M;
        a=a*a%M;
        b>>=1;
    }
    return res;
}
ll C(ll n,ll k){return (fac[n]*inv[k]%M)*inv[n-k]%M;}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fac[0]=1;
    for(int i=1;i<=MN;i++)fac[i]=fac[i-1]*i%M;
    inv[MN]=po(fac[MN],M-2);
    for(int i=MN-1;i>=0;i--)inv[i]=inv[i+1]*(i+1)%M;
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        if(n==m)
        {
            cout<<"1\n";
            continue;
        }
        cerr<<"test:"<<C(n,m)<<endl;
        long long ans=C(n,m)*fac[n-m-1]%M;
        cout<<ans<<'\n';
    }
    return 0;
}