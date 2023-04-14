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

int n,idx,ans;
long long primes[1005],dp[1005][1005];
bool vis[1005];

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

long long ask(int now,int last)
{
    if(now==0) return 1;
    if(dp[now][last]!=-1) return dp[now][last];
    long long res=0;
    for(int i=last;i<=now;i++)
    {
        if(!vis[i]) res+=ask(now-i,i);
    }
    return dp[now][last]=res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<ask(n,1)<<'\n';
    return 0;
}