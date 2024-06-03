#include<bits/stdc++.h>
using namespace std;

int f[200005];
bool vis[200005],turn[200005];
vector<int> g[200005];
queue<int> q;
map<pair<int,int>,int> mark;

void dfs(int u,int fa){
    f[u]=fa;
    bool have_son=0;
    for(int v:g[u]){
        if(vis[v])continue;
        vis[v]=1;
        have_son=1;
        dfs(v,u);
    }
    if(!have_son){
        q.push(u);
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    int N,M,K;
    cin>>N>>M>>K;
    int root=0;
    for(int i=1;i<=M;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if(!root)root=u;
        mark[{u,v}]=mark[{v,u}]=i;
    }
    if(K%2){
        cout<<"No\n";
        return 0;
    }	
    vis[root]=1;
    dfs(root,0);
    vector<int> ans;
    for(int i=1;i<=N;i++)vis[i]=0;
    while(K&&!q.empty()){
        int u=q.front();
        q.pop();
        K--;
        if(!turn[u]){
            ans.push_back(mark[{u,f[u]}]);
            turn[f[u]]=!turn[f[u]];
        }
        if(vis[f[u]])continue;
        vis[f[u]]=1;
        q.push(f[u]);
    }
    cout<<"Yes\n";
    cout<<ans.size()<<'\n';
    for(int x:ans){
        cout<<x<<" ";
    }
    cout<<'\n';
	return 0;
}

