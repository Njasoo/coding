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

int dis[N];
bool vis[N];
int head[N];
int idx;
struct Edge
{
    int to,cost,nex;
}e[M];
struct node
{
    int now,w;
    bool operator<(const node &x) const
    {
        return x.w<w;
    }
};

void add_edge(int u,int v,int w)
{
    idx++;
    e[idx].to=v;
    e[idx].nex=head[u];
    e[idx].cost=w;
    head[u]=idx;
}

void dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0;
    priority_queue<node> q;
    q.push({1,0});
    while(!q.empty())
    {
        auto [u,_]=q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].to,w=e[i].cost;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
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
        for(int j=i+1;j<=n;j++)
        {
            int c;
            cin>>c;
            add_edge(i,j,c);
        }
    }   
    dijkstra(1);
    cout<<dis[n]<<'\n';
    return 0;
}