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
        //E((a+b)^2)=
    }   
    return 0;
}