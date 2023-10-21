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
    string n;
    cin>>n;
    int ans=0;
    bool finded=0;
    for(int num=0;num<=1000;num+=8)
    {
        string s=to_string(num);
        int now=0;
        for(int i=0;i<s.size();i++)
        {
            bool flag=0;
            for(int j=now;j<n.size();j++)
            {
                if(n[j]==s[i])
                {
                    flag=1;
                    now=j+1;
                    break;
                }
            }
            if(!flag) break;
            if(i==s.size()-1)
            {
                finded=1;
                ans=num;
                break;
            }
        }
        if(finded) break;
    }
    if(!finded)
    {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<ans<<'\n';
    return 0;
}