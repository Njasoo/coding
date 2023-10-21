#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
#define p_queue priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
const int MN=2e5;
int a[N],st[N][21],lg2[N];
int n;

void build()
{
    for(int i=1;i<=n;i++)
    {
        st[i][0]=a[i];
    }
    for(int j=1;j<=20;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            st[i][j]=st[i][j-1]&st[i+(1<<(j-1))][j-1];
        }
    }
}

int query(int l,int r)
{
    int k=lg2[r-l+1];
    return st[l][k]&st[r-(1<<k)+1][k];
}

void init()
{
    lg2[1]=0;
    for(int i=2;i<=MN;i++)
    {
        lg2[i]=lg2[i/2]+1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    init();
    while(tt--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        build();
        int q;
        cin>>q;
        while(q--)
        {
            int l,k;
            cin>>l>>k;
            int L=l,R=n;
            int ans=-1;
            while(L<=R)
            {
                int mid=(L+R)/2;
                if(query(l,mid)>=k)
                {
                    L=mid+1;
                    ans=mid;
                }
                else R=mid-1;
            }
            cout<<ans<<" ";
        }
        cout<<'\n';
    }   
    return 0;
}