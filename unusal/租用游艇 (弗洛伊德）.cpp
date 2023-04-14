#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

#define db(x) cerr<<#x<<"="<<(x)<<endl
#define N 1000005
#define M 500005
#define MN 1000000
#define LOG 20
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

int dp[205][205];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,0x3f,sizeof(dp));
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int w;
            cin>>w;
            dp[i][j]=w;
        }
    }   
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    cout<<dp[1][n]<<'\n';
    return 0;
}