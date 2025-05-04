#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())

const int N=1e5+5;
ll dis[N];
int ans[N],vis[N],cnt[N],pre_min[N]; //pre_min是所有前驱u当中最小的ans[u],cnt[i]:到达i的最短路数量
int n,m;
vector<pair<ll,ll>> adj[N];

void dijkstra()
{
    for(int i=1;i<=n;i++) dis[i]=1e18;
    dis[1]=0;
    pre_min[1]=0;
    cnt[1]=1;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
    q.push({dis[1],1});
    while(!q.empty())
    {
        auto [d,u]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        ans[u]=cnt[u]-1+pre_min[u]; //从前驱选一条，然后同时还要使得前驱也是独一无二的
        // db(u),db(ans[u]),db(cnt[u]),el;
        for(auto [v,w]:adj[u])
        {
            if(d+w<dis[v])
            {
                dis[v]=d+w;
                cnt[v]=1;
                pre_min[v]=ans[u];
                q.push({dis[v],v});
            }
            else if(d+w==dis[v])
            {
                cnt[v]++;
                pre_min[v]=min(ans[u],pre_min[v]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        ll c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        if(dis[i]==1e18) cout<<"-1\n";
        else cout<<ans[i]<<"\n";
    }
    return 0;
}