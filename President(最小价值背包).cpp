#include<iostream>

using namespace std;

long long dp[100005];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=100000;i++)
    {
        dp[i]=1e18;
    }
    long long tot=0;
    for(int i=1;i<=n;i++)
    {
        long long x,y,z;
        cin>>x>>y>>z;
        tot+=z;
        long long goal=(x+y+1)/2;
        long long w;
        if(x>=goal)w=0;
        else w=goal-x;
        for(int j=100000/2+1;j>=z;j--)
        {
            dp[j]=min(dp[j],dp[j-z]+w);
        }
    }
    long long ans=1e18;
    for(int i=(tot+1)/2;i<=100000;i++)
    {
        ans=min(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}