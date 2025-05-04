#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=1e5+5;
int ans[N];
bool mark[N];
vector<int> adj[N];
struct Node{
	int s,u,d;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) ans[i]=-1;
	queue<Node> q;
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		mark[x]=1;
		q.push({x,x,0});
	}
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	while(!q.empty())
	{
		Node t=q.front();
		q.pop();
		int s=t.s,u=t.u,d=t.d;
		cerr<<u<<endl;
		for(int v:adj[u])
		{
			if(s!=v)
			{
				ans[v]=min(ans[v],d+1);
				if(!mark[v]) q.push({s,v,d+1});
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(ans[i]!=1e9) cout<<ans[i]<<" ";
		else cout<<"-1 ";
	}
	cout<<'\n';
	return 0;
}

