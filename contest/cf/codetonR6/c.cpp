#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

// #define int long long

const int N=1e5+5;
const int LOG=16;
int a[N],l[N],r[N],tag[N],st[N][LOG];
int n,k;

void build()
{
    for(int i=1;i<=n;i++)
    {
        st[i][0]=a[i];
    }
    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int l,int r)
{
    int k=(int)log2(r-l+1);
    return max(st[l][k],st[r-(1<<k)+1][k]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        cin>>n>>k;
        for(int i=1;i<=k;i++)
        {
            tag[i]=0;
            l[i]=1e9;
            r[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            tag[a[i]]=1;
        }
        build();
        for(int i=1;i<=n;i++)
        {
            // debug(l[a[i]]);
            l[a[i]]=min(l[a[i]],i);
            // debug(a[i],l[a[i]],i);
            r[a[i]]=max(r[a[i]],l[a[i]]);
            int L=i,R=n;
            int ans=-1;
            while(L<=R)
            {
                int mid=(L+R)/2;
                if(L==R)
                {
                    ans=mid;
                    break;
                }
                if(query(mid+1,R)>=a[i]) L=mid+1;
                else R=mid;
            }
            r[a[i]]=max(r[a[i]],ans);
            L=1,R=i;
            ans=-1;
            while(L<=R)
            {
                int mid=(L+R)/2;
                if(L==R)
                {
                    ans=mid;
                    break;
                }
                if(query(L,mid)>=a[i]) R=mid;
                else L=mid+1;
            }
            l[a[i]]=min(l[a[i]],ans);
        }
        for(int i=1;i<=k;i++)
        {
            if(!tag[i])
            {
                cout<<"0 ";
                continue;
            }
            // debug(i,l[i],r[i]);
            cout<<2*(r[i]-l[i]+1)<<" ";
        }
        cout<<'\n';
    }   
    return 0;
}