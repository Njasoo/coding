#include<bits/stdc++.h>

using namespace std;

#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define ll long long

//dp[i][j]: 前i个数得到j的概率
//dp[i][j]=dp[i-1][j^a[i]]*p[i]+dp[i-1][j]*(1-p[i])
const int N=2e5+5;
const ll MOD=1e9+7;
ll dp[1055],g[1055];//dp[i]: 得到i的概率
ll a[N],p[N],q[N];
int n;

ll power(ll u,ll v){
    ll res=1;
    while(v){
        if(v&1){
            res=res*u%MOD;
        }
        u=u*u%MOD;
        v>>=1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        ll inv=power(10000,MOD-2);
        for(int i=1;i<=n;i++){
            cin>>p[i];
            p[i]=p[i]*inv%MOD;
            q[i]=(1-p[i]+MOD);
        }
        for(int j=0;j<1024;j++){
            dp[j]=0;
        }
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<1024;j++){
                g[j]=dp[j];
            }
            for(int j=0;j<1024;j++){
                dp[j]=g[j^a[i]]*p[i]%MOD;
                dp[j]+=g[j]*q[i]%MOD;
                if(dp[j]>=MOD){
                    dp[j]-=MOD;
                }
            }
        }
        ll ans=0;
        for(int i=0;i<1024;i++){
            ans+=(1LL*i*i%MOD)*dp[i]%MOD;
            if(ans>=MOD){
                ans-=MOD;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}