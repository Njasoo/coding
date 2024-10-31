#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=1e5+5;
int n,a[N],bl,l[1003],r[1003],cnt,bk[N],b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    bl=sqrt(n);
    assert(bl!=0);
    for(int i=1;i<=n/bl;i++)
    {
        l[i]=r[i-1]+1;
        r[i]=l[i]+bl-1;
    }
    cnt=n/bl;
    if(r[cnt]<n)
    {
        cnt++;
        l[cnt]=r[cnt-1]+1;
        r[cnt]=n;
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=l[i];j<=r[i];j++)
        {
            bk[j]=i;
        }
        // sort(a+l[i],a+r[i]+1);
        sort(b+l[i],b+r[i]+1);
    }
    // db(cnt),el;
    int m;
    cin>>m;
    //m*sqrt(n)*log(n)
    while(m--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x,y;
            cin>>x>>y;
            a[x]=y;
            for(int i=l[bk[x]];i<=r[bk[x]];i++)
            {
                b[i]=a[i];
            }
            sort(b+l[bk[x]],b+r[bk[x]]+1);
        }
        else
        {
            int x,y,p;
            cin>>x>>y>>p;
            int bs=bk[x];
            int be=bk[y];
            int ans=0;
            if(bs==be)
            {
                for(int i=x;i<=y;i++)
                {
                    if(a[i]<a[p]) ans++;
                }
                cout<<ans+1<<" ";
                continue;
            }
            for(int i=x;i<=r[bs];i++)
            {
                if(a[i]<a[p]) ans++;
            }
            for(int i=l[be];i<=y;i++)
            {
                if(a[i]<a[p]) ans++;
            }
            for(int i=bs+1;i<be;i++)
            {
                ans+=lower_bound(b+l[i],b+r[i]+1,a[p])-(b+l[i]);
                // db(ans);
            }
            // el;
            cout<<ans+1<<" ";
        }
    }
    return 0;
}