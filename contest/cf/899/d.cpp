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

const int N=2e5+5;
vt<int> g[N];
ll a[N],ans[N];
int cnt[N];

//把儿子的值变成和父亲一样，a[v]^(a[v]^a[u])=a[u]
//然后把根换到儿子，只有两个点的代价改变了，多了父亲的代价，少了儿子的代价

void init(int u,int fa)
{
    cnt[u]=1;
    for(int v:g[u])
    {
        if(v==fa)continue;
        init(v,u);
        cnt[u]+=cnt[v];
        ans[1]+=cnt[v]*(a[u]^a[v]);
    }
}

void dfs(int u,int fa)
{
    for(int v:g[u])
    {
        if(v==fa)continue;
        ans[v]=ans[u]-cnt[v]*(a[v]^a[u])+(cnt[1]-cnt[v])*(a[v]^a[u]);//父节点的节点数为总结点减去儿子的节点数
        dfs(v,u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            g[i].clear();
            ans[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        init(1,0);
        dfs(1,0);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<'\n';
    }   
    return 0;
}