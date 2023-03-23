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

//完全背包

long long dp[1005],primes[1005];
bool vis[1005];
int idx;

void init()
{
    vis[1]=1;
    for(int i=2;i<=1000;i++)
    {
        if(!vis[i]) primes[++idx]=i;
        for(int j=1;j<=idx;j++)
        {
            if(i*primes[j]>1000) break;
            vis[i*primes[j]]=1;
            if(i%primes[j]==0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    cin>>n;
    dp[0]=1;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i])
        {
            for(int j=i;j<=n;j++)
            {
                dp[j]+=dp[j-i];
            }
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}