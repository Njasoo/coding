#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
long long a[N],h[N],dp[N],sum[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        long long n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>h[i];
        }
        int i=1;
        long long ans=0;
        int j=1;
        while(i<=n)
        {
            j=max(j,i+1);
            while(j<=n && h[j-1]%h[j]==0 && sum[j]-sum[i-1]<=k)
            {
                j++;
            }
            j--;
            // cerr<<"i="<<i<<" "<<"j="<<j<<endl;
            if(i==j && sum[j]-sum[i-1]>k) ;
            else ans=max(ans,(long long)j-i+1);
            if(j==n)break;
            i++;
        }
        cout<<ans<<'\n';
    }   
    return 0;
}