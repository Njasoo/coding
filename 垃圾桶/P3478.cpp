#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
#define p_queue priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=1e6+5;
int dep[N],siz[N];
ll dp[N],cnt[N];
vt<int> g[N];

void init(int u,int fa)
{
    dep[u]=dep[fa]+1;
    siz[u]=1;
    cnt[u]=dep[u];
    for(int v:g[u])
    {
        if(v==fa)continue;
        init(v,u);
        siz[u]+=siz[v];
        cnt[u]+=cnt[v];
    }
}

void dfs(int u,int fa)
{
    for(int v:g[u])
    {
        if(v==fa)continue;
        dp[v]=dp[u]-siz[v]+(siz[1]-siz[v]);
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }   
    init(1,0);
    // for(int i=1;i<=n;i++)
    // {
    //     debug(dep[i],i);
    //     debug(cnt[i],i);
    // }
    // debug(cnt[1]);
    dp[1]=cnt[1];
    dfs(1,0);
    ll mx=0;
    int ans=0;
    // for(int i=1;i<=n;i++)debug(dp[i],i);
    for(int i=1;i<=n;i++)
    {
        if(dp[i]>mx)
        {
            mx=dp[i];
            ans=i;
        }
    }
    cout<<ans<<'\n';
    return 0;
}