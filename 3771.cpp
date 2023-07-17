#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using pii=pair<ll,ll>;
using vpii=vector<pii>;
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const ll INF=0x3f3f3f3f3f3f3f3f;
//x-y=a[x]-a[y]->a[x]-x==a[y]-y
const int N=1e6+6;
ll cnt[N],a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]-i+200000]+=a[i];
    }
    ll ans=0;
    for(int i=0;i<N;i++){
        ans=max(ans,cnt[i]);
    }
    cout<<ans<<'\n';
    return 0;
}