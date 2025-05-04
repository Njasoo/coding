#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=2e5+5;
ll a[N];

ll tran(ll x){
    return (ll)sqrtl(x/2+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll t=a[i];
        while(t!=1){
            t=tran(t);
            ans++;
        }
    }
    for(int i=2;i<=n;i++){
        ll pre=a[i-1];
        map<ll,bool> vis;
        while(pre!=1){
            vis[pre]=true;
            pre=tran(pre);
        }
        ll t=a[i];
        while(t!=1){
            if(vis[t]){
                ans--;
            }
            t=tran(t);
        }
    }
    cout<<ans<<'\n';
    return 0;
}