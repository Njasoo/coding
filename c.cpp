#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		int pos=s.find(":");
		string sh=s.substr(0,pos);
		string sm=s.substr(pos+1);
		int h=0;
		for(int i=0;i<sh.size();i++)
		{
			h=h*10+sh[i]-'0';
		}
		string suf;
		if(h>=12) suf="PM";
		else suf="AM";
		if(h==0) h=12;
		else if(h>12) h-=12;
		string new_sh=to_string(h);
		if(new_sh.size()<2) new_sh='0'+new_sh;
		cout<<new_sh<<":"<<sm<<" "<<suf<<endl;
	}
	return 0;
}
