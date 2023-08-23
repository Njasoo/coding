#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using pii=pair<ll,ll>;
using vpii=vector<pii>;
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=1000005;
ll l,r;
int cnt;
ll f[N];
void dfs(ll now){
    if(now>=l)f[++cnt]=now;
    if(now>=r)return;   
    dfs(now*10+4);
    dfs(now*10+7);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>l>>r;
    dfs(0);
    // db(cnt);
    sort(f+1,f+1+cnt);
    // for(int i=1;i<=cnt;i++){
    //     cout<<f[i]<<" ";
    // }
    // cout<<'\n';
    int p1=lower_bound(f+1,f+1+cnt,l)-f;
    int p2=lower_bound(f+1,f+1+cnt,r)-f;
    if(p1==p2){
        cout<<f[p1]*(r-l+1)<<'\n';
        return 0;
    }
    // db(p1);
    // db(p2);
    // db(f[p1]-l+1);
    ll ans=(f[p1]-l+1)*f[p1];
    // db(ans);
    if(l==r){
        cout<<ans<<'\n';
        return 0;
    }
    for(int i=p1+1;i<p2;i++){
        ans+=(f[i]-f[i-1])*f[i];
    }
    // db(r-f[p2-1]);
    ans+=(r-f[p2-1])*f[p2];
    cout<<ans<<'\n';
    return 0;
}