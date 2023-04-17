#include<iostream>
using namespace std;

long long t[105];

int main()
{
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
    }
    long long ans=-1;
    for(int i=2;i<=n;i++)
    {
        if(t[i]-t[i-1]<=d)
        {
            ans=t[i];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}