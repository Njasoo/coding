#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<x<<endl;
const int MOD=998244353;
const int N=1e6+5;
const int MX=2005;
long long dp[MX][MX],a[N];
void init(){
    for(int i=0;i<MX;i++){
        dp[i][0]=1;
        dp[i][1]=i;
    }
    for(int i=1;i<MX;i++){
        for(int j=1;j<MX;j++){
            dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        long long ans=0;
        for(int j=0;j<=x;j++){
            ans=(ans+dp[x][j]*a[y])%MOD;
            y=y%n+1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}