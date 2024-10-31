#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=1e5+5,LOG=21;
int h[N],f[N],lg[N],st[N][LOG],n; //f[i]: i左边第一个>=h[i]的下标

void build()
{
    for(int i=1;i<=n;i++)
        st[i][0]=h[i];
    for(int i=2;i<=n;i++)
        lg[i]=lg[i/2]+1;
    for(int j=1;j<LOG;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}

int query(int l,int r)
{
    int k=lg[r-l+1];
    return min(st[l][k],st[r-(1<<k)+1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    build();
    vector<int> stk;
    for(int i=1;i<=n;i++)
    {
        while(!stk.empty() && h[stk.back()]<h[i])
        {
            stk.pop_back();
        }
        if(!stk.empty()) f[i]=stk.back();
        else f[i]=0;
        stk.push_back(i);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     db(i),db(f[i]),el;
    // }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int lo=f[i]+1,hi=i-1;
        if(lo>hi) continue;
        int min_val=query(f[i]+1,i-1);
        // db(f[i]+1),db(i-1),db(min_val),el;
        // int bans=0;
        while(lo<hi)
        {
            int mid=(lo+hi)/2;
            if(query(mid+1,hi)==min_val) lo=mid+1; //lo!=mid,而是mid+1,因为这里的区间是[mid+1,hi]
            else hi=mid; //这里说明只有[l,mid]是有最小值的,hi应该赋值为mid
        }
        // db(i),db(bans),el;
        ans=max(ans,i-lo+1);
    }
    cout<<ans<<'\n';
    return 0;
}