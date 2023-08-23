#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+5;
ll a[N];
ll n,k;
bool check(ll mid)
{
    ll cnt=0;
    for(int i=n/2+1;i<=n;i++)
    {
        if(a[i]>=mid)break;
        cnt+=mid-a[i];
    }
    return cnt<=k;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    ll l=0,r=1e12;
    ll ans=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans<<'\n';
    return 0;
}