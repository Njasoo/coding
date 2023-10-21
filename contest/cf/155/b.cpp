#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=3e5+5;
ll a[N],b[N];

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
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        ll ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            ans1+=a[i]+b[1];
            ans2+=b[i]+a[1];
        }
        cout<<min(ans1,ans2)<<'\n';
    }   
    return 0;
}