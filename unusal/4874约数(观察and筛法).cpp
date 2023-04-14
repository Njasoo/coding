#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int N=10000005;
const int MN=10000000;
const int MOD=998244353;
const long long INF=0x3f3f3f3f3f3f3f3f;
int vis[N],primes[N];
int idx;
void init()
{
    vis[1]=1;
    for(int i=2;i<=MN;i++)
    {
        if(!vis[i])primes[++idx]=i;
        for(int j=1;j<=idx;j++)
        {
            if(i*primes[j]>MN)break;
            vis[i*primes[j]]=1;
            if(i%primes[j]==0)break;
        }
    }
}
bool issquare(long long x)
{
    long long rootx=sqrt(x);
    return rootx*rootx==x;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        if(issquare(x) && !vis[int(sqrt(x))])cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}