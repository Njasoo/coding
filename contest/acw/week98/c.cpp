#include<iostream>
#include<cmath>
using namespace std;

int m;
bool check1(long long mid)
{
    long long cnt=0;
    long long now=1;
    while(mid/(long long)pow(5,now)!=0)
    {
        cnt+=mid/(long long)pow(5,now);
        now++;
    }
    return cnt>=m;
}
bool check2(long long mid)
{
    long long cnt=0;
    long long now=1;
    while(mid/(long long)pow(5,now))
    {
        cnt+=mid/pow(5,now);
        now++;
    }
    return cnt<=m;
}

int main()
{
    cin>>m;
    long long l=1,r=1e18;
    long long ans1=-1,ans2=-1;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check1(mid))
        {
            r=mid-1;
            ans1=mid;
        }
        else l=mid+1;
    }
    l=1,r=1e18;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if(check2(mid))
        {
            l=mid+1;
            ans2=mid;
        }
        else r=mid-1;
    }
    cout<<ans2-ans1+1<<endl;
    if(ans2-ans1+1==0) return 0;
    for(long long i=ans1;i<=ans2;i++)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}