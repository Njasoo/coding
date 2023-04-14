#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define sz(x) (int)(x).size()
const int N=1e5+5;
int ls[N][2],deleted[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        if(p){
            int k_r=ls[k][1];
            ls[k][1]=i;
            ls[i][0]=k;
            ls[k_r][0]=i;
            ls[i][1]=k_r;
        }else{
            int k_l=ls[k][0];
            ls[i][1]=k;
            ls[k][0]=i;
            ls[k_l][1]=i;
            ls[i][0]=k_l;
        }
    }   
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        if(deleted[x])continue;
        deleted[x]=1;
        int x_l=ls[x][0],x_r=ls[x][1];
        ls[x_l][1]=x_r;
        ls[x_r][0]=x_l;
    }
    int now=0;
    for(int i=1;i<=n;i++){
        if(ls[i][0]==0){
            now=i;
            break;
        }
    }
    while(now){
        cout<<now<<" ";
        now=ls[now][1];
    }
    cout<<'\n';
    return 0;
}