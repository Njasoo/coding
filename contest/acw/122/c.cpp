#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const long long MOD=1e9+7;
long long power(long long u,long long v)
{
    long long res=1;
    while(v)
    {
        if(v&1)res=res*u%MOD;
        u=u*u%MOD;
        v>>=1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //考虑一个位的贡献
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt[4]={0};
    for(char c:s)
    {
        if(c=='A')cnt[0]++;
        if(c=='C')cnt[1]++;
        if(c=='G')cnt[2]++;
        if(c=='T')cnt[3]++;
    }
    sort(cnt,cnt+4);
    if(cnt[3]>cnt[2])cout<<"1\n";
    else if(cnt[3]==cnt[2] && cnt[2]>cnt[1])cout<<power(2,n)<<'\n';
    else if(cnt[3]==cnt[2] && cnt[2]==cnt[1] && cnt[1]>cnt[0])cout<<power(3,n)<<'\n';
    else cout<<power(4,n)<<'\n';
    return 0;
}