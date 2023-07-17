#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<endl
const ll INF=0x3f3f3f3f3f3f3f3f;
const int N=5e6+5;
ll x[N],y[N],c[N],k[N];
int f[N];
int find(int x){
    if(x==f[x])return x;
    return f[x]=find(f[x]);
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    f[y]=x;
}
bool same(int x,int y){
    return find(x)==find(y);
}
ll dis(int i,int j){
    return llabs(x[i]-x[j])+llabs(y[i]-y[j]);
}
struct Edge{
    ll u,v,w;
}e[N];
bool cmp(Edge i,Edge j){
    return i.w<j.w;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];   
    for(int i=1;i<=n;i++){
        cin>>c[i];
        e[++cnt]={0,i,c[i]};
    }
    for(int i=1;i<=n;i++)cin>>k[i];
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            e[++cnt]={i,j,dis(i,j)*(k[i]+k[j])};
        }
    }
    sort(e+1,e+1+cnt,cmp);
    vector<ll> ans1;
    vector<pair<ll,ll>> ans2;
    ll ans=0;
    for(int i=1;i<=cnt;i++){
        ll u=e[i].u,v=e[i].v,w=e[i].w;
        if(same(u,v))continue;
        merge(u,v);
        ans+=w;
        if(u==0){
            ans1.push_back(v);
            continue;
        }
        ans2.push_back({u,v});
    }
    cout<<ans<<'\n';
    cout<<ans1.size()<<'\n';
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<'\n';
    cout<<ans2.size()<<'\n';
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i].first<<" "<<ans2[i].second<<'\n';
    }
    return 0;
}