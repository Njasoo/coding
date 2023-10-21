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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            cin>>a;
            if(a==k)flag=1;
        }
        cout<<(flag?"YES":"NO")<<'\n';
    }   
    return 0;
}