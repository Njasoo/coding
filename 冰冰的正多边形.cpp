#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define ll long long

int cnt[105];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=100;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			cnt[a]++;
		}
		int ans=1e9;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]>=3)
			{
				ans=min(ans,i*3);
			}
		}
		if(ans==1e9)cout<<"no\n";
		else
		{
			cout<<"yes\n";
			cout<<ans<<'\n';
		}
	}	
	return 0;
}

