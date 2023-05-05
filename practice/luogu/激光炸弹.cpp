#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int sum[N][N];
int read() {
    int x = 0, f = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0', ch = getchar();
    }
    return x * f;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n=read(),m=read();
    int maxx=0,maxy=0;
    for(int i=1;i<=n;i++)
    {
        int x=read(),y=read(),v=read();
        x++,y++;
        maxx=max(maxx,x);
        maxy=max(maxy,y);
        sum[x][y]=v;
    }   
    for(int i=1;i<=maxx;i++)
    {
        for(int j=1;j<=maxy;j++)
        {
            sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }
    int ans=0;
    if(m>maxx || m>maxy)
    {
        if(m>maxx)
        {
            for(int j=m;j<=maxy;j++)
            {
                ans=max(ans,sum[maxx][j]-sum[maxx][j-m]);
            }
        }
        if(m>maxy)
        {
            for(int i=m;i<=maxx;i++)
            {
                ans=max(ans,sum[i][maxy]-sum[i-m][maxy]);
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    for(int i=m;i<=maxx;i++)
    {
        for(int j=m;j<=maxy;j++)
        {
            ans=max(ans,sum[i][j]-sum[i-m][j]-sum[i][j-m]+sum[i-m][j-m]);
        }
    }
    cout<<ans<<'\n';
    return 0;
}