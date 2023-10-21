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

const int N=105;
ll b[N];

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
            ll a;
            cin>>a;
            if(b[i-1]+1!=a)b[i]=b[i-1]+1;
            else b[i]=a+1;
        }
        cout<<b[n]<<'\n';
    }   
    return 0;
}