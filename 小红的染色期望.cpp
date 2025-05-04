#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

const int N=1e6+5;
const ll MOD=1e9+7;
ll dp[N],sum[N];

ll power(ll u,ll v)
{
    ll res=1;
    while(v)
    {
        if(v%2) res=res*u%MOD;
        u=u*u%MOD;
        v/=2;
    }
    return res;
}

ll inv(ll x)
{
    return power(x,MOD-2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=0;
    // dp[2]=1;
    for(int i=1;i<=2;i++)
    {
        sum[i]=sum[i-1]+dp[i];
    }
    for(int i=2;i<=n;i++)
    {
        // for(int j=1;j+1<=n;j++)
        // {
        //     dp[i]+=1+dp[j-1]+dp[n-j-1];
        //     // db(dp[j-1]),db(dp[n-j-1]),el;
        //     if(dp[i]>=MOD) dp[i]-=MOD;
        // }
        dp[i]=2*sum[i-2]%MOD;
        dp[i]+=i-1;
        if(dp[i]>=MOD) dp[i]-=MOD;
        dp[i]*=inv(i-1);
        dp[i]%=MOD;
        sum[i]=sum[i-1]+dp[i];
    }
    cout<<dp[n]<<"\n";
    return 0;
}