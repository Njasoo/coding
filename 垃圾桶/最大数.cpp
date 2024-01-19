#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;
long long a[N],tr[N<<2];
int m;
long long MOD;

void update(int id,int l,int r,int s,int e,long long k)
{
    if(s<=l&&r<=e)
    {
        tr[id]=k;
        return;
    }
    int mid=(l+r)/2;
    if(s<=mid)update(id<<1,l,mid,s,e,k);
    if(e>mid)update(id<<1|1,mid+1,r,s,e,k);
    tr[id]=max(tr[id<<1],tr[id<<1|1])%MOD;
}

long long query(int id,int l,int r,int s,int e)
{
    if(s<=l&&r<=e)return tr[id];
    int mid=(l+r)/2;
    long long res=-1e18;
    if(s<=mid)res=max(res,query(id<<1,l,mid,s,e));
    if(e>mid)res=max(res,query(id<<1|1,mid+1,r,s,e));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>m>>MOD;
    long long t=0;
    int now_len=0;
    for(int i=1;i<=m;i++)
    {
        char op;
        long long x;
        cin>>op>>x;
        if(op=='A')
        {
            x=(x+t)%MOD;
            x+=MOD;
            x%=MOD;
            now_len++;
            update(1,1,m,now_len,now_len,x);
        }
        else
        {
            t=query(1,1,m,now_len-x+1,now_len);
            cout<<t<<'\n';
        }
    } 
    return 0;
}