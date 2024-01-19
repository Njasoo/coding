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

const int N=1e5+5;
vt<pair<ll,ll>> g[N];
ll tot_dis[N],c[N],dis[N],dp[N],siz[N];

void init(int u,int fa)
{
    siz[u]=c[u];
    tot_dis[u]=dis[u]*c[u];
    for(auto [v,w]:g[u])
    {
        if(v==fa)continue;
        dis[v]=dis[u]+w;
        init(v,u);
        tot_dis[u]+=tot_dis[v];
        siz[u]+=siz[v];
    }
}

void dfs(int u,int fa)
{
    for(auto [v,w]:g[u])
    {
        if(v==fa)continue;
        dp[v]=dp[u]-w*siz[v]+(siz[1]-siz[v])*w;
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<n;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    init(1,0);
    debug(tot_dis[5]);
    for(int i=1;i<=n;i++)debug(i,dis[i]);
    debug(tot_dis[1]);
    dp[1]=tot_dis[1];
    dfs(1,0);
    ll ans=1e18;
    for(int i=1;i<=n;i++)ans=min(ans,dp[i]);
    cout<<ans<<'\n';
    return 0;
}