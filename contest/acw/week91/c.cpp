#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int m,n;
vector<vector<int>> f;
int check(int mid)
{
    for(int j=1;j<=n;j++)
    {
        int c=0;
        for(int i=1;i<=m;i++)
        {
            if(f[i][j]>=mid)
            {
                c=1;
                break;
            }
        }
        if(!c)return 0;
    }
    if(n>m)return 1;
    for(int i=1;i<=m;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(f[i][j]>=mid)cnt++;
        }
        if(cnt>=2)return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>m>>n;
        f=vector<vector<int>>(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>f[i][j];
            }
        }
        int l=1,r=1e9;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        cout<<ans<<'\n';
    }
    return 0;
}