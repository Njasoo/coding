#include <iostream>
#include <set>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		s=' '+s;
		for(int i=1;i<=n;i++)
		{
			if(n%i==0)
			{
				int cnt=0;
				for(int j=1;j<=i;j++)
				{
					for(int k=j;k<=n;k+=i)
					{
						if(s[k]!=s[j]) cnt++;
					}
				}
				if(cnt<=1)
				{
					cout<<i<<endl;
					break;
				}
				cnt=0;
				for(int j=1;j<=i;j++)
				{
					for(int k=n+1-j;k>=1;k-=i)
					{
						if(s[k]!=s[n+1-j]) cnt++;
					}
				}
				if(cnt<=1)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
