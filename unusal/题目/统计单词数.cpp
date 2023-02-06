#include<iostream>
using namespace std;
int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='A' && a[i]<='Z')
		{
			a[i]=a[i]-'A'+'a';
		}
	}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]>='A' && b[i]<='Z')
		{
			b[i]=b[i]-'A'+'a';
		}
	}
	a=' '+a+' ';//关键的一步
	b=' '+b+' ';
	auto pos=b.find(a),ans_pos=b.find(a);
	int ans=0;
	while(pos!=string::npos)
	{
		ans++;
		pos=b.find(a,pos+1);
	}
	if(ans)cout<<ans<<" "<<ans_pos<<endl;
	else cout<<-1<<endl;
	return 0;
}