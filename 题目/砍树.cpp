#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
ll n,m,k,l,r,mid;
ll a[1000005],b[1000005];
bool f(ll x)
{
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(x<a[i])
        {
            ans+=a[i]-x;
        }
    }
    return ans>=m;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }   
    l=0,r=1e9+1;
    while(l+1<r)
    {
        mid=l+(r-l)/2;
        if(f(mid)) l=mid;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}