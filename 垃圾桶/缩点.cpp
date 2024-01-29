#include <iostream>
#include <vector>
using namespace std;

int a[10005],dfn[10005],s[10005],low[10005],belong[10005],_u[100005],_v[100005],in[10005];
int id,top,ans,cnt;
vector<int> g[10005];
bool instack[10005];

void dfs(int u){
    dfn[u]=low[u]=++id;
    s[++top]=u;
    instack[u]=1;
    for(int v:g[u]){
        if(!dfn[v]) dfs(v);
        if(instack[v]) low[u]=min(low[u],low[v]);
    }
    if(dfn[u]==low[u]){
        // printf("u=%d\n",u);
        while(s[top]!=u){
            belong[s[top]]=u;
            a[u]+=a[s[top]];
            instack[s[top]]=0;
            top--;
        }
        top--;
        belong[u]=u;
        instack[u]=0;
    }
}

void dfs2(int u,int cnt){
    ans=max(ans,cnt);
    for(int v:g[u]){
        dfs2(v,cnt+a[v]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>_u[i]>>_v[i];
        g[_u[i]].push_back(_v[i]);
    }
    for(int i=1;i<=n;i++){
        if(!dfn[i]) dfs(i);
    }
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=m;i++){
        if(belong[_u[i]]!=belong[_v[i]]){
            // printf("belong[_u[i]]=%d,belong[_v[i]]=%d\n",belong[_u[i]],belong[_v[i]]);
            // printf("u[i]=%d,v[i]=%d\n",_u[i],_v[i]);
            g[belong[_u[i]]].push_back(belong[_v[i]]);
            in[_v[i]]++;
        }
    }
    for(int i=1;i<=n;i++){
        // printf("belong[i]=%d,i=%d,in[i]=%d\n",belong[i],i,in[i]);
        if(belong[i]==i && in[i]==0){
            dfs2(i,a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}