#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define endl '\n'
#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
//lalala~~~
/*
*/
int my_compare(string s1,string s2)
{
    if(s1==s2)return 0;
    if(s1.size()==s2.size())
        if(s1>s2)return 1;
        else return -1;
    else
        if(s1.size()>s2.size())return 1;
        else return -1;
}
//hahaha!!!
int f[105][105];
int dx1[13]={2,0,-2,0,1,1,1,0,0,0,-1,-1,-1};
int dy1[13]={0,2,0,-2,0,1,-1,1,0,-1,0,1,-1};
int dx2[25]={-2,-2,-2,-2,-2,-1,-1,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
int dy2[25]={-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2,-2,-1,0,1,2};
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;      
    int ans=0;
    for(int j=1;j<=m;j++)
    {
        int x,y;
        cin>>x>>y;
        for(int i=0;i<13;i++)
        {
            int xx=x+dx1[i];
            int yy=y+dy1[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=n)f[xx][yy]=1;
        }
    }
    for(int j=1;j<=k;j++)
    {
        int o,p;
        cin>>o>>p;
        for(int i=0;i<25;i++)
        {
            int xx=o+dx2[i];
            int yy=p+dy2[i];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=n)f[xx][yy]=1;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(f[i][j]==0)ans++;
    cout<<ans<<endl;
    return 0;
}