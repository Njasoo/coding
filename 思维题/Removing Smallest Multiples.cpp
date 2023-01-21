#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
#define endl '\n'
int n,T[1000005],S[1000005];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--)
	{
		cin>>n;
		cin>>s;
		s=' '+s;
		for(int i=1;i<=n;i++)
		{
			T[i]=0;
			S[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			T[i]=1;
			if(s[i]=='1')S[i]=1;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j+=i)
			{
				if(T[j]==1 && S[j]==0)
				{
					T[j]=0;
					ans+=i;
				}
				if(T[j]==1 && S[j]==1)
				{
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}