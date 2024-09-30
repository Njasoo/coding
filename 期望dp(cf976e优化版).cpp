#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define ll long long

//dp[i][b1][b2][ii][jj]: 前i个数第ii位为b1,第jj为b2的概率
//然后仿照O(1024*n)的做法
const int N=2e5+5;
const ll MOD=1e9+7;
ll a[N],p[N],q[N];

ll power(ll u,ll v){
    ll res=1;
    while(v){
        if(v%2){
            res=res*u%MOD;
        }
        u=u*u%MOD;
        v/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    const ll inv=power(10000,MOD-2);
    while(tt--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>p[i];
            p[i]=p[i]*inv%MOD;
            q[i]=(1-p[i]+MOD);
        }
        ll ans=0;
        for(int b1=0;b1<10;b1++){
            for(int b2=0;b2<10;b2++){
                ll dp[2][2]{};
                dp[0][0]=1;
                for(int i=1;i<=n;i++){
                    ll g[2][2];
                    for(int bit1:{0,1}){
                        for(int bit2:{0,1}){
                            g[bit1][bit2]=dp[bit1][bit2];
                        }
                    }
                    for(int bit1:{0,1}){
                        for(int bit2:{0,1}){
                            dp[bit1][bit2]=g[bit1^(a[i]>>b1&1)][bit2^(a[i]>>b2&1)]*p[i]%MOD;
                            dp[bit1][bit2]+=g[bit1][bit2]*q[i]%MOD;
                            if(dp[bit1][bit2]>=MOD){
                                dp[bit1][bit2]-=MOD;
                            }
                        }
                    }
                }
                //f(S)=b20b19...b0
                //f(S)^2=simga(bi*bj*2^(i+j))
                ans+=(1<<(b1+b2))*dp[1][1]%MOD;//只有bi bj都是1才有贡献
                if(ans>=MOD){
                    ans-=MOD;
                }
            }
        }
        cout<<ans<<'\n';
    }   
    return 0;
}