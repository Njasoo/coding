#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
int vis[N];
long long dis[N];
vector<int> g[N];
int in_cycle[N],cycle[N];
int cnt,start,dont_find;

void find_cycle(int u,int idx,int fa)
{
    if(dont_find) return;
    if(vis[u])
    {
        // cerr<<"Hello"<<endl;
        // cerr<<"u="<<u<<endl;
        // for(int i=1;i<idx;i++)
        // {
        //     cerr<<cycle[i]<<" ";
        // }
        // cerr<<endl;
        for(int i=1;i<idx;i++)
        {
            if(cycle[i]==u) start=1;
            if(!start) continue;
            in_cycle[cycle[i]]=1;
        }
        dont_find=1;
        return;
    }
    vis[u]=1;
    cycle[idx]=u;
    for(int v:g[u])
    {
        // if(vis[v]) continue;//习惯了，这里不要加这句
        if(v==fa) continue;
        find_cycle(v,idx+1,u);
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
        int n,a,b;
        cin>>n>>a>>b;
        start=0;
        dont_find=0;
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
            vis[i]=0;
            in_cycle[i]=0;
            dis[i]=1e18;
        }
        for(int i=1;i<=n;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(a==b)
        {
            cout<<"NO\n";
            continue;
        }
        find_cycle(b,1,0);
        // cerr<<"Vertex in the cycle:"<<endl;
        // for(int i=1;i<=n;i++)
        // {
        //     if(in_cycle[i])
        //     {
        //         cerr<<i<<" ";
        //     }
        // }
        // cerr<<endl;
        // cerr<<"done"<<endl;
        if(in_cycle[b])
        {
            cout<<"YES\n";
            continue;
        }
        dis[b]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        q.push({0LL,b});
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        while(!q.empty())
        {
            auto [d,u]=q.top();
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int v:g[u])
            {
                if(d+1<dis[v])
                {
                    dis[v]=d+1;
                    q.push({dis[v],v});
                }
            }
        }
        long long mn_dis=1e18;
        int entrance=-1;
        for(int i=1;i<=n;i++)
        {
            if(in_cycle[i])
            {
                if(dis[i]<mn_dis)
                {
                    entrance=i;
                    mn_dis=dis[i];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            vis[i]=0;
            dis[i]=1e18;
        }
        while(!q.empty())
        {
            q.pop();
        }
        dis[a]=0;
        q.push({0LL,a});
        while(!q.empty())
        {
            auto [d,u]=q.top();
            q.pop();
            if(vis[u]) continue;
            vis[u]=1;
            for(int v:g[u])
            {
                if(d+1<dis[v])
                {
                    dis[v]=d+1;
                    q.push({dis[v],v});
                }
            }
        }
        // debug(mn_dis,dis[entrance],entrance);
        if(mn_dis<dis[entrance]) cout<<"YES\n";
        else cout<<"NO\n";
    }   
    return 0;
}