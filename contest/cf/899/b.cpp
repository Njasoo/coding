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

const int N=55;
ll s[N];

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
        ll S=0;
        for(int i=1;i<=50;i++)s[i]=0;
        for(int i=1;i<=n;i++)
        {
            int k;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                ll e;
                cin>>e;
                s[i]|=(1LL<<e);
            }
            S|=s[i];
        }
        // debug(S);
        ll ans=0;
        for(int i=1;i<=50;i++)
        {
            if((S>>i&1)==0)continue;
            ll cnt=0;
            for(int j=1;j<=n;j++)
            {
                if((s[j]>>i&1)==0)
                {
                    cnt|=s[j];
                }
            }
            ans=max(ans,(ll)__builtin_popcountll(cnt));
        }
        cout<<ans<<'\n';
    }   
    return 0;
}