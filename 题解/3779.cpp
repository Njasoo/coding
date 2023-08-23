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
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+5;
ll a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin>>k;
    bool flag=0;
    map<ll,pii> hs;
    for(int i=1;i<=k;i++){
        int n;
        cin>>n;
        ll sum=0;
        for(int j=1;j<=n;j++){
            cin>>a[j];
            sum+=a[j];
        }
        // if(flag)continue;
        for(int j=1;j<=n;j++){
            ll temp=sum-a[j];
            if(hs.count(temp)&&hs[temp].fi!=i){
                // flag=1;
                cout<<"YES"<<endl;
                cout<<i<<" "<<j<<endl;
                cout<<hs[temp].fi<<" "<<hs[temp].se<<endl;
                return 0;
            }
            hs[temp]={i,j};
        }
    }   
    cout<<"NO"<<endl;
    return 0;
}