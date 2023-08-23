#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<ll>;
using pii=pair<ll,ll>;
using vpii=vector<pii>;
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=105;
ll a[N],sum;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int odd=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        odd+=a[i]%2;
        sum+=a[i];
    }   
    if(sum%2==0){
        cout<<n-odd<<'\n';
    }else{
        cout<<odd<<'\n';
    }
    return 0;
}