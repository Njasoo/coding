#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long cnt=0,ans=-1e18;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        cnt+=a;
        if(cnt<0)cnt=a;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}