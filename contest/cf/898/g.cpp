#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

//AAAB->AABC->ABCC->BCCC B从右往左
//BAAA->CBAA->CCBA->CCCB

const int N=2e5+5;
long long dp[N][2];

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
        int n=s.size();
        s=' '+s;
        vector<int> pos(1);
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='B')
            {
                pos.push_back(i);
            }
        }
        pos.push_back(n+1);
        if(pos.size()==2)
        {
            cout<<"0\n";
            continue;
        }
        else if(pos.size()==3)
        {
            cout<<max(pos[1]-1,n-pos[1])<<'\n';
            continue;
        }
        long long ans=0;
        for(int i=1;i<(int)pos.size()-1;i++)
        {
            dp[i][0]=dp[i-1][0]+pos[i]-pos[i-1]-1;
            dp[i][1]=max(dp[i-1][0],dp[i-1][1])+pos[i+1]-pos[i]-1;
        }
        cout<<max(dp[pos.size()-2][0],dp[pos.size()-2][1])<<'\n';
    }   
    return 0;
}