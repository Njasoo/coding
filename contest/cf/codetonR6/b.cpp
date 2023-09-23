#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        int tot_a=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            tot_a^=a[i];
        }
        int tot_b=0;
        for(int i=1;i<=m;i++)
        {
            int b;
            cin>>b;
            tot_b|=b;
        }
        if(n%2==0)
        {
            int ans1=0;
            for(int i=1;i<=n;i++)
            {
                a[i]|=tot_b;
                ans1^=a[i];
            }
            cout<<ans1<<" "<<tot_a<<'\n';
        }
        else
        {
            int ans2=0;
            for(int i=1;i<=n;i++)
            {
                a[i]|=tot_b;
                ans2^=a[i];
            }
            cout<<tot_a<<" "<<ans2<<'\n';
        }
    }   
    return 0;
}