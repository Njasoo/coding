#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<endl
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=105;
//每个进制位只能出现至多一次
ll a[N],cnt[105];
void solve(){
    memset(cnt,0,sizeof(cnt));
    int n,k;
    cin>>n>>k;
    int flag=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int idx=0;
        while(a[i]){
            int num=a[i]%k;
            if(num!=1&&num!=0)flag=0;
            a[i]/=k;
            if(num)cnt[idx]++;
            idx++;
        }
    }
    if(!flag){
        // cerr<<"Hello1"<<endl;
        cout<<"NO\n";
        return;
    }
    for(int i=0;i<N;i++){
        if(cnt[i]>1){
            // cerr<<"Hello2"<<endl;
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)solve();   
    return 0;
}