#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

//[l,r]=w 带来一个信息，s[r]-s[l-1]=w，考虑在l-1到r之间建边权为w的边，还有-w的反向边
//单纯考虑是否有解就是一个可到达性的问题，用并查集就能做
//但是怎么求距离
//考虑求每个集合中编号最小的点到集合当中所有点的距离，只要是同一个集合，这个编号最小的点必然相等，这部分的时间复杂度为O(n)
const int N=1e5+5;
vector<pair<int,long long>> adj[N];
int n,m,q,f[N];
bool vis[N];
long long s[N];

int find(int x){
        if(x==f[x]) return x;
        return f[x]=find(f[x]);
}

void merge(int x,int y){
        x=find(x);
        y=find(y);
        f[y]=x;
}

bool same(int x,int y){
        return find(x)==find(y);
}

void bfs(int u){
        s[u]=0;
        vis[u]=true;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
                int u=q.front();
                q.pop();
                for(auto [v,w]:adj[u]){
                        if(vis[v]) continue;
                        vis[v]=true;
                        s[v]=s[u]+w;
                        q.push(v);
                }
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++) f[i]=i;
        for(int i=1;i<=m;i++){
                int l,r;
                cin>>l>>r;
                long long w;
                cin>>w;
                adj[l-1].push_back({r,w});
                adj[r].push_back({l-1,-w});
                merge(l-1,r);
        }
        for(int i=0;i<=n;i++){
                if(!vis[i]){
                        bfs(i);
                }
        }
        while(q--){
                int l,r;
                cin>>l>>r;
                if(!same(l-1,r)) cout<<"UNKNOWN\n";
                else cout<<s[r]-s[l-1]<<'\n';
        }
        return 0;
}