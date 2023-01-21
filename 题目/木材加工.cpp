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
        ans+=a[i]/x;//计算每根木头可以切成多少份
    }
    return ans>=k;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }   
    l=0,r=1e8+1;
    while(l+1<r)//l恒小于r,所以判断条件为l+1<r
    {
        mid=l+(r-l)/2;
        if(f(mid))l=mid;//如果符合条件,尝试把每一根都变大一点
        else r=mid;//不行说明太大了
    }
    cout<<l<<endl;
    return 0;
}