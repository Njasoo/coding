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
    int h,m;
    cin>>h>>m;
    int cnt1=h*60+m;
    int cnt2=24*60;
    cout<<cnt2-cnt1<<'\n'; 
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)solve();  
    return 0;
}