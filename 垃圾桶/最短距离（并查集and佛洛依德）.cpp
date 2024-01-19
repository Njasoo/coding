#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include<cassert>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

//只需在一个类中拿出一个点，跑dijk,时间复杂度：O(nklogn)

int n,m,k;
vector<pair<int,int>> g[100005];
bool vis[100005],tag[505];
int c[505],f[100005],dp[505][505],id[100005],anc[100005];

int leader(int x){
    if(x==f[x])return x;
    return f[x]=leader(f[x]);
}

bool same(int x,int y){
    x=leader(x);
    y=leader(y);
    return (x==y);
}

void unite(int x,int y){
    x=leader(x);
    y=leader(y);
    f[y]=x;
}

int find_id(int x){
    int l=1,r=k;
    int res=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(x<=c[mid]){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            dp[i][j]=(int)1e9;
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        c[i]+=c[i-1];
    }   
    for(int i=1;i<=n;i++){
        f[i]=i;
        id[i]=find_id(i);
    }
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dp[id[u]][id[v]]=dp[id[v]][id[u]]=min(dp[id[u]][id[v]],w);
        if(w==0){//只有边权为零的边有价值
            unite(u,v);
        }
    }
    // assert(0);
    bool ok=1;
    for(int i=1;i<=n;i++){
        anc[i]=leader(i);
    }
    for(int kk=1;kk<=k;kk++){
        for(int i=c[kk-1]+1;i<c[kk];i++){
            if(anc[i]!=anc[i+1]){
                ok=0;
                break;
            }
        }
    }
    if(!ok){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(i==j)dp[i][j]=0;
        }
    }
    for(int kk=1;kk<=k;kk++){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=min(dp[i][j],dp[i][kk]+dp[kk][j]);
            }
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(dp[i][j]==(int)1e9){
                cout<<"-1 ";
            }else{
                cout<<dp[i][j]<<" ";
            }
        }
        cout<<'\n';
    }
    return 0;
}