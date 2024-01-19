#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
vector<pair<int,long long>> g[N];
long long dis[N][N],s[N];
bool vis[N][N];
//简单地来说就是求从1到n的最短路，但是问题在于边权是不固定的，但其实我们可以稍微地转化这个问题，这个图他不一定是n个结点的图
//可以是1000*n个结点的图，即考虑了我从这个点出发的时候的单车slowness factor是什么的情况
//过程当中的小贪心，如果现在我能买到更快的单车，那我肯定买
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)g[i].clear();
        for(int i=1;i<=m;i++){
            int u,v;
            long long w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        priority_queue<tuple<long long,int,long long>,vector<tuple<long long,int,long long>>,greater<>> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=1000;j++){
                dis[i][j]=1e18;
            }
        }
        dis[1][s[1]]=0;
        q.push({0,1,s[1]});
        while(!q.empty()){
            auto [d,u,s_now]=q.top();
            q.pop();
            if(vis[u][s_now])continue;
            vis[u][s_now]=1;
            for(auto [v,w]:g[u]){
                long long c=min(s[v],s_now);//很简单的贪心，当我现在要去到的城市能买到的单车的slowness factor是更小的，那我肯定换
                if(dis[v][c]>dis[u][s_now]+w*s_now){
                    dis[v][c]=dis[u][s_now]+w*s_now;
                    q.push({dis[v][c],v,c});
                }
            }
        }
        long long ans=1e18;
        for(int j=1;j<=1000;j++){
            ans=min(ans,dis[n][j]);
        }
        cout<<ans<<'\n';
    }
    return 0;
}