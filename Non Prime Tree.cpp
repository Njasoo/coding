#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=2e5+5,MN=4e5;
int ans[N],isprime[N*2],deg[N],vis[2*N];
vector<int> adj[N],primes,heshu;

struct Node
{
	int d,u;
	bool operator<(const Node& rhs)const
	{
		return !(d<rhs.d);
	}
};

void init()
{
	for(int i=2;i<=MN;i++) isprime[i]=1;
	for(int i=2;i<=MN;i++)
	{
		if(isprime[i]) primes.push_back(i);
		for(int p:primes)
		{
			if(i*p>MN) break;
			isprime[i*p]=0;
			if(i%p==0) break;
		}
	}
	for(int i=1;i<=MN;i++) if(!isprime[i]) heshu.push_back(i);
}

bool cmp(int i,int j)
{
	return deg[i]>deg[j];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
//	for(int i=0;i<10;i++) cout<<heshu[i]<<" ";
//	cout<<endl;
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			ans[i]=0;
			deg[i]=0;
			vis[i]=0,vis[2*i]=0;
			adj[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for(int i=1;i<=n;i++) sort(adj[i].begin(),adj[i].end(),cmp);
		priority_queue<Node> q;
		int mx_id=0,mx=0;
		for(int i=1;i<=n;i++)
		{
			if(deg[i]>mx)
			{
				mx=deg[i];
				mx_id=i;
			}
		}
		q.push((Node){mx,mx_id});
		ans[mx_id]=1;
		vis[1]=1;
		int flag=1;
		while(!q.empty())
		{
			Node node=q.top();
			int u=node.u;
			int d=node.d;
			q.pop();
			int p=0;
			for(int v:adj[u])
			{
				if(ans[v]) continue;
				while(p<heshu.size() && vis[ans[u]+heshu[p]]) p++;
				if(p==heshu.size())
				{
					flag=0;
					break;
				}
				else if(u+heshu[p]>2*n)
				{
					flag=0;
					break;
				}
				ans[v]=ans[u]+heshu[p];
				vis[ans[u]+heshu[p]]=1;
				q.push((Node){deg[v],v});
			}
			if(!flag) break;
		}
		if(!flag) cout<<"-1\n";
		else
		{
			for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
			cout<<'\n';
		}
	}	
	return 0;
}

