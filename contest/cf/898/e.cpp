#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
int n,k;
long long a[N];

bool check(long long mid)
{
    long long cnt=0;
    for(int i=1;i<=n;i++)
    {
        cnt+=max(0LL,mid-a[i]);
    }
    return cnt<=k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long l=1,r=1e12;
        long long ans=-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            if(check(mid))
            {
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }   
    return 0;
}