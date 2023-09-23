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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        s=" "+s;
        vector<int> pos;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='B')pos.push_back(i);
        }
        int ans=0;
        if(pos.size()==0)
        {
            cout<<"0\n";
            continue;
        }
        int now=pos[0];
        while(1)
        {
            ans++;
            int r=now+k-1;
            auto it=upper_bound(pos.begin(),pos.end(),r);
            if(it==pos.end())break;
            now=*it;
        }
        cout<<ans<<'\n';
    }   
    return 0;
}