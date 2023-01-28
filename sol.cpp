#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<x<<endl;
//从每一个黑点开始染色，更新最短距离,加一点点剪枝
const int N=2e5+5;
int n,ans;
int c[N],dis[N];
vector<int> p[N];
void update(int u,int val){
    if(val>=dis[u]||val>=ans) return;
    dis[u]=val;
    for(int v:p[u]) update(v,val+1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n>>c[0];
        for(int i=1;i<=n;i++){
            p[i].clear();
            dis[i]=n-1;
        }
        for(int i=1;i<n;i++) cin>>c[i];
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            p[u].push_back(v);
            p[v].push_back(u);
        }
        ans=n-1;
        update(c[0],0);
        for(int i=1;i<n;i++){
            ans=min(ans,dis[c[i]]);
            if(ans>1) update(c[i],0);//ans随着染色不打断减小
            cout<<ans<<' ';
        }
        cout<<'\n';
    }       
    return 0;
}