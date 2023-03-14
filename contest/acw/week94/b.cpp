#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl
const int N=1e5+5;
int n,m;
struct Edge{
    int to,cost;
};
vector<Edge> p[N];
vector<int> t[N];
int ans[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;   
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        p[a].push_back({b,c});
        p[b].push_back({a,c});
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int temp;
            cin>>temp;
            t[i].push_back(temp);
        }
    }
    queue<pair<int,int>> q;//(id,time)
    q.push({1,0});
    memset(ans,-1,sizeof(ans));
    while(!q.empty()){
        auto [id,nowt]=q.front();
        q.pop();
        for(auto [to,cost]:p[id]){

        }
    }
    return 0;
}