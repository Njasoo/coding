#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define vt vector
#define pb push_back
#define sz(x) (int)x.size()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const ll MOD=998244353;
const int N=2e5+5;
const int MN=2e5;
ll fac[N],inv_fac[N];

ll power(ll u,ll v)
{
    ll res=1;
    while(v)
    {
        if(v&1)res=res*u%MOD;
        u=u*u%MOD;
        v>>=1;
    }
    return res;
}

void init()
{
    fac[0]=1;
    for(int i=1;i<=MN;i++)fac[i]=fac[i-1]*i%MOD;
    inv_fac[MN]=power(fac[MN],MOD-2);
    for(int i=MN-1;i>=0;i--)inv_fac[i]=inv_fac[i+1]*(i+1)%MOD;
}

ll C(ll n,ll k)
{
    return (fac[n]*inv_fac[k]%MOD)*inv_fac[n-k]%MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        s+='#';
        char nex;
        if(s[0]=='0')nex='1';
        else nex='0';
        string goal="";
        goal+=s[0];
        for(int i=1;i<(int)s.size();i++)
        {
            if(s[i]==nex)
            {
                goal+=s[i];
                nex=(nex-'0')^1+'0';
            }
        }
        ll ans=1;
        // debug(goal);
        int now=0;
        for(int i=0;i<(int)goal.size();i++)
        {
            ll cnt=0;
            for(int j=now;j<(int)s.size();j++)
            {
                if(s[j]!=goal[i])
                {
                    ans=ans*C(cnt,cnt-1)%MOD;
                    // cerr<<"C(cnt,cnt-1)="<<C(cnt,cnt-1)<<endl;
                    now=j;
                    break;
                }
                cnt++;
            }
            // debug(i,cnt);
        }
        ll dis=s.size()-goal.size()-1;
        // debug(dis);
        for(int i=2;i<=dis;i++)
        {
            ans=ans*i%MOD;
        }
        cout<<dis<<" "<<ans<<'\n';
    }   
    return 0;
}