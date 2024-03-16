# include <iostream>
# include <stdlib.h>
# define N 1000005
# define MAX_DIST 2000000000000000000LL

using namespace std; 

int vis[1003][1003];
int n,m,a,b,c,dx[]={-1,0,0,1},dy[]={0,-1,1,0};
long long dist_a[1003][1003],dist_b[1003][1003],dist_c[1003][1003],r[1003][1003],ans=MAX_DIST;
long long dist[1003][1003];
struct {
    int x,y;
} heap[1000003];
int heap_cnt;

bool heap_greater(int u,int v){return dist[heap[u].x][heap[u].y]>dist[heap[v].x][heap[v].y];}

void swap_(int u,int v){
    int x=heap[u].x,y=heap[u].y;
    heap[u].x=heap[v].x;heap[u].y=heap[v].y;
    heap[v].x=x;heap[v].y=y;
    vis[heap[u].x][heap[u].y]=u;
    vis[heap[v].x][heap[v].y]=v;
}

int heap_down(int cur){
    if(2*cur+1>heap_cnt-1)
        return -1;
    if(2*cur+1==heap_cnt-1){
        if(heap_greater(cur,2*cur+1))
            swap_(cur,2*cur+1);
        return -1;
    }
    if(heap_greater(2*cur+1,cur) && heap_greater(2*cur+2,cur))
        return -1;
    if(heap_greater(2*cur+1,2*cur+2)){
        swap_(cur,2*cur+2);
        return 2*cur+2;
    }
    else{
        swap_(cur,2*cur+1);
        return 2*cur+1;
    }
}
int heap_up(int cur){
    if(cur==0 || heap_greater(cur,(cur-1)/2)) return -1;
    swap_(cur,(cur-1)/2);
    return (cur-1)/2;
}

int heap_adjust_down(int cur){while((cur=heap_down(cur))!=-1);}
int heap_adjust_up(int cur){while((cur=heap_up(cur))!=-1);}

void dijkstra(int a,int b){
    int end_x,end_y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            vis[i][j]=-1;//unvisited
        }
    dist[a][b]=0;vis[a][b]=-2;//ensured
    heap_cnt=0;
    for(int k=0;k<4;k++)
        if(a+dx[k]>0 && a+dx[k] <=n && b+dy[k]>0 && b+dy[k]<=m){
            dist[a+dx[k]][b+dy[k]]=r[a+dx[k]][b+dy[k]];
            heap[heap_cnt].x=a+dx[k];
            heap[heap_cnt].y=b+dy[k];
            vis[a+dx[k]][b+dy[k]]=heap_cnt++;
        }
    for(int i=heap_cnt/2-1;i>=0;i--)
        heap_adjust_down(i);
    while(heap_cnt){
        //extract min
        end_x=heap[0].x;end_y=heap[0].y;
        heap[0].x=heap[--heap_cnt].x;heap[0].y=heap[heap_cnt].y;
        vis[heap[0].x][heap[0].y]=0;
        heap_adjust_down(0);
        vis[end_x][end_y]=-2;
        for(int k=0;k<4;k++)
            if(end_x+dx[k]>0 && end_x+dx[k]<=n && end_y+dy[k]>0 && end_y+dy[k]<=m && vis[end_x+dx[k]][end_y+dy[k]]!=-2){
                if(vis[end_x+dx[k]][end_y+dy[k]]==-1){
                    dist[end_x+dx[k]][end_y+dy[k]]=dist[end_x][end_y]+r[end_x+dx[k]][end_y+dy[k]];
                    vis[end_x+dx[k]][end_y+dy[k]]=heap_cnt;
                    heap[heap_cnt].x=end_x+dx[k];heap[heap_cnt].y=end_y+dy[k];
                    heap_cnt++;
                    heap_adjust_up(heap_cnt-1);
                }
                else if(dist[end_x+dx[k]][end_y+dy[k]]>dist[end_x][end_y]+r[end_x+dx[k]][end_y+dy[k]]){
                    dist[end_x+dx[k]][end_y+dy[k]]=dist[end_x][end_y]+r[end_x+dx[k]][end_y+dy[k]];
                    heap_adjust_up(vis[end_x+dx[k]][end_y+dy[k]]);
                }
            }
    }
}

void distcpy(long long dist1[1003][1003],long long dist2[1003][1003]){
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dist1[i][j]=dist2[i][j];
}

int main(){
    cin>>n>>m>>a>>b>>c;
    for(int i=n;i>0;i--)
        for(int j=1;j<=m;j++){
            scanf("%lld",&r[i][j]);
            dist_a[i][j]=dist_b[i][j]=dist_c[i][j]=MAX_DIST;
        }
    distcpy(dist,dist_a);
    dijkstra(n,a);
    distcpy(dist_a,dist);
    distcpy(dist,dist_b);
    dijkstra(1,b);
    distcpy(dist_b,dist);
    distcpy(dist,dist_c); 
    dijkstra(1,c);
    distcpy(dist_c,dist);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(ans>dist_a[i][j]+dist_b[i][j]+dist_c[i][j]+r[n][a]+r[1][b]+r[1][c]-2*r[i][j]){
                ans=dist_a[i][j]+dist_b[i][j]+dist_c[i][j]+r[n][a]+r[1][b]+r[1][c]-2*r[i][j];
            }
    return printf("%lld",ans),0;
}