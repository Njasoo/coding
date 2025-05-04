#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<"\n"

const int N=2e5+5;
int a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		bool flag=1;
		for(int i=0;i<31;i++)
		{
			if((y>>i&1) && (!(x>>i&1)))
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			cout<<"NO\n";
			continue;
		}
		for(int j=0;j<31;j++)
		{
			if(x>>j&1)
			{
				for(int i=1;i<=n;i++)
				{
					a[i]|=1<<j;
				}
			}
		}
		for(int j=0;j<31;j++)
		{
			if((y>>j&1) && (x>>j&1))
			{
				if(n%2==0) a[1]^=1<<j;
			}
			if(!(y>>j&1) && (x>>j&1))
			{
				if(n%2) a[1]^=1<<j;
			}
		}
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<" \n"[i==n];
		}
	}
	return 0;
}

