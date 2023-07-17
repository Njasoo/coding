#include<bits/stdc++.h>
using namespace std;
int f[200005],siz[200005],a[200005];
int g[200005];
int vis[200005],ans[200005];
int find(int x)
{
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
int merge(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y)return 0;
    f[y]=x;
    siz[x]+=siz[y];
    return 1;
}
int size(int x)
{
    return siz[find(x)];
}
void dfs(int now)
{
    while(now)
    {
        vis[now]=1;
        ans[now]=size(now);
        now=g[now];
        if(vis[now])break;
    }
}
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
        memset(g,0,sizeof(g));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            f[i]=i;
            siz[i]=1;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            merge(a[i],i);
            g[i]=a[i];
            g[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
        {
            dfs(i);
        }
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }   
    return 0;
}