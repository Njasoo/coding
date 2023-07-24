#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using mii=map<ll,ll>;
#define endl '\n'
#define vi vector
#define pque priority_queue
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define il inline
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=1000000007;
il ll fpow(ll u,ll v){
    ll res=0;
    while(v){
        if(v&1)res=res*u%MOD;
        v>>=1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll x[4];
    for(int i=0;i<4;i++){
        cin>>x[i];
    }   
    sort(x,x+4);
    for(int i=2;i>=0;i--){
        cout<<x[3]-x[i]<<" ";
    }
    cout<<endl;
    return 0;
}