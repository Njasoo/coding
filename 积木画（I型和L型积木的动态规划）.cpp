#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=1e7+5;
const ll MOD=1e9+7;
ll dp[N][3]; //dp[i][0]:两行相等，dp[i][1]:上面凸一个，dp[i][2]:下面凸一个

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    dp[0][0]=1;
    dp[1][0]=1; //两行相等
    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-2][0]+dp[i-1][1]+dp[i-1][2])%MOD;
        dp[i][1]=(dp[i-2][0]+dp[i-1][2])%MOD;
        dp[i][2]=(dp[i-2][0]+dp[i-1][1])%MOD;
    }
    cout<<dp[n][0]<<'\n';
    return 0;
}