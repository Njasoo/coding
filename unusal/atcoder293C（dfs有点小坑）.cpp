#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define endl '\n'
#define sz(x) (int)(x).size()
const int N=15;
int n,m;
int f[N][N],vis[N][N],path[N<<1],temp_path[N<<1];
int dir[2][2]={1,0,0,1};
int ans;
void dfs(int x,int y,int now){
    if(x==n&&y==m){
        memcpy(temp_path,path,sizeof(path));
        sort(temp_path+1,temp_path+now);
        int len=unique(temp_path+1,temp_path+now)-(temp_path+1);
        if(len==now-1){
            ans++;
        }
        return;
    }
    for(int k=0;k<2;k++){
        int xx=x+dir[k][0];
        int yy=y+dir[k][1];
        if(xx>=1 && xx<=n && yy>=1 && yy<=m && !vis[xx][yy]){
            vis[xx][yy]=1;
            path[now]=f[xx][yy];
            dfs(xx,yy,now+1);
            vis[xx][yy]=0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>f[i][j];
        }
    }
    vis[1][1]=1;
    path[1]=f[1][1];
    dfs(1,1,2);
    cout<<ans<<endl;
    return 0;
}