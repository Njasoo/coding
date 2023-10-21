#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
#define p_queue priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
ll a[N];

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
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<max(0LL,a[1])<<'\n';
            continue;
        }
        for(int i=3;i<=n;i++)
        {
            ans+=max(0LL,a[i]);
        }
        ans=max({ans,ans+a[1]+a[2],ans+a[1]});
        cout<<ans<<'\n';
    }   
    return 0;
}