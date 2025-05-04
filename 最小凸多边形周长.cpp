#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

//最长的边小于其他边总和，则可以成为一个多边形
const int N=105,M=10005;
bool dp[M],odp[M];
ll a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=0;i<=n*a[n];i++){
            dp[i]=0;
        }
        dp[0]=1;
        ll ans=1e18;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=n*a[n];j++){
                odp[j]=dp[j];
                if(j>a[i]&&odp[j]) ans=min(ans,a[i]+j);
                dp[j]=0;
            }
            for(int j=0;j<=n*a[n];j++){
                if(j-a[i]>=0){
                    dp[j]|=odp[j-a[i]];
                }else{
                    dp[j]|=odp[j];
                }
            }
        }
        cout<<(ans==1e18?-1:ans)<<"\n";
    }
    return 0;
}