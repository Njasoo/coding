#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int a[1000005],b[1000005],d[1000005],f[1000005],tag[1000005];
int find(int x)
{
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y)
{
    x=find(x);
    y=find(y);
    f[y]=x;
}
bool same(int x,int y)
{
    return find(x)==find(y);
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
        for(int i=0;i<=n;i++)
        {
            f[i]=i;
            tag[i]=0;
        }
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=1;i<=n;i++)cin>>d[i];
        for(int i=1;i<=n;i++)
        {
            if(d[i])merge(0,d[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==b[i])merge(0,a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            merge(a[i],b[i]);
        }
        long long ans=1;
        for(int i=1;i<=n;i++)
        {
            if(same(0,i))continue;
            if(tag[find(i)]==0)
            {
                tag[find(i)]=1;
                ans*=2;
                ans%=1000000007;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}