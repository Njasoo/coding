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
    a[1]=1,a[2]=3;
    for(int i=3;i<=200000;i++)a[i]=i+2;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cout<<a[i]<<" ";
        cout<<'\n';
    }   
    return 0;
}