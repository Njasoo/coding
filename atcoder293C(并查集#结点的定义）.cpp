#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define endl '\n'
#define sz(x) (int)(x).size()
const int N=2e5+5;
int n,m;
int f[N<<1],siz[N<<1];
int leader(int x){
    while(x!=f[x])x=f[x]=f[f[x]];
    return x;
}
bool merge(int x,int y){
    x=leader(x);
    y=leader(y);
    if(x==y)return 0;
    f[y]=x;
    siz[x]+=siz[y];
    return 1;
}
bool same(int x,int y){
    return leader(x)==leader(y);
}
int size(int x){
    return siz[leader(x)];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n<<1;i++){
        f[i]=i;
        siz[i]=1;
    }
    for(int i=1;i<=n;i++){
        merge(i,i+n);
    }
    int cnt=0;
    for(int i=1;i<=m;i++){
        int x,y;
        char cx,cy;
        cin>>x>>cx>>y>>cy;
        if(cx=='B'){
            x+=n;
        }
        if(cy=='B'){
            y+=n;
        }
        if(!merge(x,y)){
            cnt++;
        }
    }
    int cnt2=0;
    for(int i=1;i<=n;i++){
        if(f[i]==i){
            cnt2++;
        }
    }
    cout<<cnt<<" "<<cnt2-cnt<<endl;
    return 0;
}