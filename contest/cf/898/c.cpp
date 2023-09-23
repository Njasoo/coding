#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

int score[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    int start=1,end=10;
    int now_score=1;
    while(start<=end)
    {
        for(int j=start;j<=end;j++)
        {
            score[start][j]=now_score;
        }
        for(int i=start+1;i<=end;i++)
        {
            score[i][end]=now_score;
        }
        for(int j=end-1;j>=start;j--)
        {
            score[end][j]=now_score;
        }
        for(int i=end-1;i>=start+1;i--)
        {
            score[i][start]=now_score;
        }
        start++,end--;
        now_score++;
    }
    // for(int i=1;i<=10;i++)
    // {
    //     for(int j=1;j<=10;j++)
    //     {
    //         cout<<score[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    while(tt--)
    {
        long long ans=0;
        for(int i=1;i<=10;i++)
        {
            for(int j=1;j<=10;j++)
            {
                char ch;
                cin>>ch;
                if(ch=='X')ans+=score[i][j];
            }
        }
        cout<<ans<<'\n';
    }   
    return 0;
}