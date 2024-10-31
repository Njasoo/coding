#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	string title;
	cin>>title;
	string t1,t2;
	int pos=-1;
	for(int i=0;i<b.size();i++)
	{
		if(b[i]!=',')
		{
			t1+=b[i];
		}
		else
		{
			pos=i+1;
			break;
		}
	}
	for(int i=pos;i<b.size();i++)
	{
		if(b[i]!=']')
		{
			t2+=b[i];
		}
		else
		{
			break;
		}
	}
	cout<<title<<"("<<t1<<","<<t2<<")"<<'\n';
	return 0;
}

