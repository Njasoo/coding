#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define sz(x) (int)(x).size()
int n,m;
const int N=2e6+5;
int a[N],t[N<<2];
void build(int id,int l,int r){
    if(l==r){
        t[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=min(t[id<<1],t[id<<1|1]);
}
int query(int id,int l,int r,int s,int e){
    if(l==s && r==e){
        return t[id];
    }
    int mid=(l+r)>>1;
    if(e<=mid){
        return query(id<<1,l,mid,s,e);
    }else if(s>mid){
        return query(id<<1|1,mid+1,r,s,e);
    }else{
        return min(query(id<<1,l,mid,s,mid),query(id<<1|1,mid+1,r,mid+1,e));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;   
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    cout<<0<<'\n';
    for(int i=2;i<=n;i++){
        cout<<query(1,1,n,max(1,i-m),i-1)<<'\n';
    }
    return 0;
}