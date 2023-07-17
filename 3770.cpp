#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using pii=pair<ll,ll>;
using vpii=vector<pii>;
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const ll INF=0x3f3f3f3f3f3f3f3f;
void solve(){
    int n,a,b,c;
    string s;
    cin>>n>>a>>b>>c>>s;
    s=' '+s;
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0')ans+=min(a,b+c);
        else ans+=min(a+c,b);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)solve();
    return 0;
}