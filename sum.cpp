#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;
ll a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ll n,sum;
		cin>>n>>sum;
		ll cur=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cur+=a[i];
		}
		if(sum==cur)
		{
			cout<<"0\n";
			continue;
		}
		sort(a+1,a+1+n);
		int ans=0;
		if(cur<sum)
		{
			for(int i=1;i<=n;i++)
			{
				ll change=10000-a[i];
				ans++;
				if(change+cur>=sum) break;
				cur+=change;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				ll change=-10000-a[i];
				ans++;
				if(change+cur<=sum) break;
				cur+=change;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

