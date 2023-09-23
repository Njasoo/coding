#include <bits/stdc++.h>

using namespace std;

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
        string s;
        cin>>s;
        if(s=="abc" || s=="acb" || s=="bac" || s=="cba")cout<<"YES\n";
        else cout<<"NO\n";
    }   
    return 0;
}