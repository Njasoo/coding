#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<x<<endl;
const int N=2e5+5;
int n,m;
int f[N];
int leader(int x){
    while(x!=f[x]) x=f[x]=f[f[x]];
    return x;
}
bool merge(int x,int y){
    x=leader(x);
    y=leader(y);
    if(x==y) return 0;
    f[y]=x;
    return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    bool flag=1;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        if(!merge(u,v)) flag=0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i]==i) cnt++;
    }
    if(cnt!=1) flag=0;
    cout<<(flag?"Yes":"No")<<'\n';
    return 0;
}