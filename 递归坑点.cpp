#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

int dir[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
int n,k;
bool vis[15][15],line[15][15][15][15];
int ps[105],a[15][15];

void dfs(int x,int y,int cur,int cnt)
{
    if(a[x][y]!=cur) return;
    if(vis[x][y]) return;
    // db(x),db(y),el;
    vis[x][y]=1;
    if(x==n && y==n && cnt==n*n)
    {
        for(int i=1;i<cnt;i++)
        {
            cout<<ps[i];
        }
        cout<<"\n";
        exit(0);
        // vis[x][y]=0;
        return;
    }
    int nex=(cur+1)%k;
    for(int t=0;t<8;t++)
    {
        int nx=x+dir[t][0];
        int ny=y+dir[t][1];
        if(nx>=1 && nx<=n && ny>=1 && ny<=n)
        // if(nx>=1 && nx<=n && ny>=1 && ny<=n && !vis[nx][ny])
        {
            if(t==1)
            {
                if(line[x-1][y][x][y+1]) continue;
                line[x][y][nx][ny]=line[nx][ny][x][y]=1;
            }
            if(t==3)
            {

                if(line[x+1][y][x][y+1]) continue;
                line[x][y][nx][ny]=line[nx][ny][x][y]=1;
            }
            if(t==5)
            {
                if(line[x+1][y][x][y-1]) continue;
                line[x][y][nx][ny]=line[nx][ny][x][y]=1;
            }
            if(t==7)
            {
                if(line[x-1][y][x][y-1]) continue;
                line[x][y][nx][ny]=line[nx][ny][x][y]=1;
            }
            ps[cnt]=t;
            dfs(nx,ny,nex,cnt+1);
            if(t%2) line[x][y][nx][ny]=line[nx][ny][x][y]=0;
            //我想到了，为什么要先判断vis[nx][ny]==0，因为有可能有两个方向相反，但是覆盖格子相同的路径，我没有判断格子是否走过
            //我直接进去了，然后马上又出来，结果清路径的时候把原本合法的路径也清了，能多判断一点还是多判断一点吧
            // vis[nx][ny]=0;
        }
    }
    vis[x][y]=0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    dfs(1,1,0,1);
    cout<<"-1\n";
    return 0;
}