/**
 * 暴力枚举i个结点的最大生成树
 * 猜想，i个结点的最大生成树包含点权最大的点，这个结论好像不成立
 * dp[i]：考虑前i个结点能得到的最大的树的点权和(X)
 * 树形dp，dp[i][1]:包含结点i的i的子树的最大点权和
 * dp[i][0]:不包含结点i的i的子树的最大点权和
 * 上面的dp有问题，不需要考虑不选择i为根节点的情况，当不选择v的父节点u，v也不可能选
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N=16005;
int a[N],n,dp[N];
vector<int> adj[N];

void solve(int u,int fa)
{
    dp[u]=a[u];
    // if(u==7)
    // {
    //     printf("a[7]=%d\n",a[7]);
    //     printf("dp[7][1]=%d\n",dp[7][1]);
    //     printf("dp[7][0]=%d\n",dp[7][0]);
    // }
    // printf("adj[7].size()=%d\n",adj[7].size());
    for(int v:adj[u])
    {
        if(v==fa)continue;
        solve(v,u);
        // if(u==7) printf("v=%d\n",v);
        if(dp[v]>0) dp[u]+=dp[v];
        // printf("dp[%d][1]=%d\n",v,dp[v][1]);
        // printf("dp[%d][0]=%d\n",v,dp[v][0]);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // for(int v:adj[7])
    // {
    //     printf("v=%d ",v);
    // }
    // puts("");
    solve(1,0);
    int ans=-1e9;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    // printf("dp[1][1]=%d\n",dp[1][1]);
    // printf("dp[1][0]=%d\n",dp[1][0]);
    return 0;
}