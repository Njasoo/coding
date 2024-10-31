#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define chkmin(a,b) a=(a<b?a:b)
#define chkmax(a,b) a=(a>b?a:b)

//dp[i][x][y]: 考虑前i个人, group1达到x, group2达到y的最小转移次数
ll dp[505][505],a[105],b[105],g[505][505];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=b[i];
    }
    if(sum%3){
        cout<<"-1\n";
        return 0;
    }
    for(int j=0;j<=sum/3;j++){
        for(int k=0;k<=sum/3;k++){
            dp[j][k]=1e18;
        }
    }
    ll cur_sum=0;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum/3;j++){
            for(int k=0;k<=sum/3;k++){
                g[j][k]=dp[j][k];
            }
        }
        cur_sum+=b[i];
        for(int j=0;j<=sum/3;j++){
            for(int k=0;k<=sum/3;k++){
                dp[j][k]=1e18;//避免被上一层状态影响
                if(j>=b[i])chkmin(dp[j][k],g[j-b[i]][k]+(a[i]!=1));
                if(k>=b[i])chkmin(dp[j][k],g[j][k-b[i]]+(a[i]!=2));
                if(cur_sum-j-k>=b[i])chkmin(dp[j][k],g[j][k]+(a[i]!=3));
            }
        }
    }
    ll ans=dp[sum/3][sum/3];
    if(ans==1e18)cout<<"-1\n";
    else cout<<ans<<'\n';
    return 0;
}