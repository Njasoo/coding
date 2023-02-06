#include<iostream>
#include<cmath>
using namespace std;
#define endl '\n'
int a[100005];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int temp=a[i];//要加上这句，不然a[i]会被a[j+1]改掉
		for(int j=i-1;j>=0;j--)
		{
			if(temp>=a[j] || j==0)
			{
				a[j+1]=temp;
				break;
			}
			else
			{
				a[j+1]=a[j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
	return 0;
}