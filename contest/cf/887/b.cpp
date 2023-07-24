#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
using mii=map<ll,ll>;
#define endl '\n'
#define vt vector
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
int n,k;
ll F[N];
void solve();
bool check(){
    for(int i=3;i<=min(n,k);i++){
        a[i]=a[i-1]+a[i-2];
        if(a[i]>=n){
            if(i<k)return 0;
            else return 1;
        }
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    F[1]=F[2]=1;
    for(int i=3;i<=50;i++)F[i]=F[i-1]+F[i-2];
    int tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}
void solve(){
    cin>>n>>k;
    //f[k]=n;
    //f[i]=f[i-1]+f[i-2]
    //f[k]=f[k-1]+f[k-2]
    //n=f[k-1]+f[k-2]=f[k-2]+f[k-3]+f[k-2]=2f[k-2]+f[k-3]=2(f[k-3]+f[k-4])+f[k-3]=3f[k-3]+f[k-4]=...=(k-2)f[2]+f[1]
    //f[1]=0,f[2]=0;
    //n=(k-2)f[2]+f[1]
    //f[2]=(f[1]-n)/(k-2)
    //f[1]=f[2]*(k-2)+n
    //f[2]=(1 to n);
    ll ans=0;
    if(k>=50){
        cout<<"0"<<endl;
        return;
    }
    for(int i=0;i<=n;i++){
        a[1]=i;
        if((n-F[k-2]*a[1])%F[k-1])continue;
        a[2]=(n-F[k-2]*a[1])/F[k-1];
        if(a[2]<a[1])continue;
        ans+=check();
    }
    cout<<ans<<endl;
}