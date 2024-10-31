#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=3005;
ll w[N][N],d[N];
bool vis[N];
struct Node{
	ll d,u;
	bool operator<(const Node& rhs)const{
		return !(d<rhs.d);
	}
};

ll calc(int a,int b){
	ll res=0;
	while(a||b){
		int da=a%10;
		int db=b%10;
		if(da!=db){
			res+=da+db;
		}
		a/=10;
		b/=10;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=2021;i++){
		for(int j=i+1;j<=2021;j++){
			w[i][j]=w[j][i]=calc(i,j);
		}
	}	
	priority_queue<Node> q;
	for(int i=2;i<=2021;i++){
		d[i]=1e18;
	}
	q.push((Node){d[1],1});
	int tot=0;
	ll ans=0;
	while(!q.empty()&&tot<2021){
		Node u=q.top();
		q.pop();
		ll dis=u.d;
		int _u=u.u;
		if(vis[_u])continue;
		vis[_u]=1;
		tot++;
		ans+=dis;
		for(int j=1;j<=2021;j++){
			if(j==_u)continue;
			if(w[_u][j]<d[j]){
				d[j]=w[_u][j];
				q.push((Node){d[j],j});
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

