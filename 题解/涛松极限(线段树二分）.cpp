#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int t[N<<2],a[N];

void build(int id,int l,int r){
    if(l==r){
        t[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    t[id]=max(t[id<<1],t[id<<1|1]);
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
        return max(query(id<<1,l,mid,s,mid),query(id<<1|1,mid+1,r,mid+1,e));
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }   
    build(1,1,n);
    for(int i=1;i<n;i++){
        if(query(1,1,n,i+1,n)<=a[i]){
            cout<<0<<'\n';
            continue;
        }
        int l=i+1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            if(query(1,1,n,l,mid)>a[i]){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<r-i<<'\n';
    }
    cout<<0<<'\n';
    return 0;
}