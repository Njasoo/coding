#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=105;
int f[N],a[N],d[N];

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
    x=find(x);
    y=find(y);
    return x==y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=i;
    }   
    for(int i=1;i<=n;i++)
    {
        cin>>d[i];
        //i-j=d[i] or i-j=-d[i]-> j=i-d[i] or j=i+d[i]
        if(i+d[i]<=n) merge(i,i+d[i]);
        if(i-d[i]>=1) merge(i,i-d[i]);
    }
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        if(!same(i,a[i]))
        {
            flag=0;
            break;
        }
    }
    if(flag) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}