#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=105;
int s[N],e[N];

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
            cin>>s[i]>>e[i];
        }
        bool flag=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i]>=s[1]&&e[i]>=e[1])
            {
                flag=0;
                break;
            }
        }
        if(flag)cout<<s[1]<<'\n';
        else cout<<"-1\n";
    }
    return 0;
}