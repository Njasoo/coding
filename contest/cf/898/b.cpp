#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=105;
long long a[N];

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
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            long long cnt=1;
            for(int j=1;j<=n;j++)
            {
                cnt*=a[j]+(i==j);
            }
            ans=max(ans,cnt);
        }
        cout<<ans<<'\n';
    }   
    return 0;
}