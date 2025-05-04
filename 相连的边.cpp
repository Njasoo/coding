#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=2e5+5;
int n;
vector<pair<ll,ll>> adj[N];

void dfs(int u,int p)
{
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		ll v,w;
		cin>>v>>w;
		adj[i].push_back(pair<ll,ll>({v,w}));
		adj[v].push_back(pair<ll,ll>({i,w}));
	}	
	dfs(1,0);
	return 0;
}

