#include<iostream>
#include<algorithm>
using namespace std;

struct Edge
{
	int from,to,cost;
}e[100005];

int f[305];
int cnt;

int find(int x)
{
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}

bool merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y)return 0;
	f[y]=x;
	return 1;
}

bool cmp(Edge i,Edge j)
{
	return i.cost<j.cost;
}

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		int w;
		cin>>w;
		e[++cnt]={0,i,w};
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			if(i==j)continue;
			e[++cnt]={i,j,w};
		}
	}
	sort(e+1,e+1+cnt,cmp);
	long long ans=0;
	for(int i=1;i<=cnt;i++)
	{
		if(merge(e[i].from,e[i].to))ans+=e[i].cost;
	}
	cout<<ans<<endl;
	return 0;
}