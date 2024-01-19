#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstdlib>

using namespace std;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second

const int N=3e5+5;
const ll MOD=998244353;
ll pref[N];

void add(ll &a,ll b){
    a+=b;
    if(a>=MOD)a-=MOD;
}

ll sum(ll a,ll b){
    a+=b;
    if(a>=MOD)a-=MOD;
    if(a<0)a+=MOD;
    return a;
}

ll mul(ll a,ll b){
    return a*b%MOD;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll a;
        cin>>a;
        pref[i]=pref[i-1]^a;
    }
    ll ans=0;
    for(int j=0;j<30;j++){
        ll cnt[2]={1,0};
        ll cur=0;
        ll sumOfL[2]={0};
        for(int i=1;i<=n;i++){
            int x=pref[i]>>j&1;
            ll sumOfR=mul(cnt[x^1],i);
            // add(cur,sum(sumOfR,-sumOfL[x^1]));
            cnt[x]++;
            add(sumOfL[x],i);
            // ll sumOfR=cnt[x^1]*i%MOD;
            cur=(cur+(((sumOfR-sumOfL[x^1])%MOD)+MOD)%MOD)%MOD;
            // cnt[x]++;
            // sumOfL[x]=(sumOfL[x]+i)%MOD;
        }
        // ans=(ans+cur*(1<<j)%MOD)%MOD;
        add(ans,mul(cur,1<<j));
    }
    cout<<ans<<endl;
    return 0;
}