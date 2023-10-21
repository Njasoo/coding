#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
ll c[N],a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
        }
        ll k;
        cin>>k;
        for(int i=n-1;i>=1;i--)
        {
            c[i]=min(c[i],c[i+1]);
        }
        //带悔贪心
        a[0]=1e18;
        ll pre=0;
        for(int i=1;i<=n;i++)
        {
            ll change_cost=c[i]-c[i-1];
            if(change_cost==0)
            {
                a[i]=a[i-1];
                continue;
            }
            //不能超过a[i-1]
            a[i]=k/change_cost;
            if(a[i]>a[i-1])
            {
                k-=pre*change_cost;
                a[i]=a[i-1];
                continue;
            }
            pre=k/change_cost;
            k-=k/change_cost*change_cost;
        }
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<'\n';
    }   
    return 0;
}