#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
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
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define il inline
#define cn const
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define lb lower_bound
#define up upper_bound
#define re reverse
cn int N=1e6+5;
cn int MN=1e6;
ll a[N];
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=1000000007;
void solve();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}
void solve(){
    int n;
    cin>>n;
    if(n%2==0){
        for(int i=n;i>=1;i--){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++){
        a[i]=n+1-i;
    }
    swap(a[n/2+1],a[n/2]);
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
}