#include <iostream>
#include <vector>
using namespace std;

int calc(int num)
{
	string s;
	while(num)
	{
		s.push_back(char(num%2+'0'));
		num/=2;
	}
	int res=0;
	for(int i=s.size()-1;i>=0;i--)
	{
		res=res*10+s[i]-'0';
	}
	return res;
}

int main()
{
	vector<int> nums;
	for(int i=2;i<=64;i++)
	{
		nums.push_back(calc(i));
//		cout<<nums.back()<<" ";
	}
//	cout<<endl;
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=nums.size()-1;i>=0;i--)
		{
			while(n%nums[i]==0)
			{
				n/=nums[i];
			}
		}
//		cout<<"n="<<n<<endl;
		if(n==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}	
	return 0;
}

