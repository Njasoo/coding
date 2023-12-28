#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct Node{
    long long a;
    int id;
    char g;
}t[N];
struct Node2{
    long long dis;
    int id1,id2;
    bool operator<(const Node2& x)const{
        if(dis==x.dis)return id1>x.id1;
        return dis>x.dis;
    }
};
bool del[N];
int lb[N][2];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=' '+s;
    for(int i=1;i<=n;i++){
        t[i].g=s[i];
        t[i].id=i;
    }
    for(int i=1;i<=n;i++){
        cin>>t[i].a;
    }
    lb[0][1]=1;
    lb[1][0]=0;
    for(int i=2;i<=n;i++){
        lb[i-1][1]=i;
        lb[i][0]=lb[i-2][1];
    }
    lb[n][1]=0;
    priority_queue<Node2> q;
    for(int i=1;i<n;i++){
        if(t[i].g!=t[i+1].g)q.push({llabs(t[i].a-t[i+1].a),t[i].id,t[i+1].id});
    }
    // int now=1;
    // while(now){
    //     cerr<<"now="<<now<<" ";
    //     now=lb[now][1];
    // }
    // cerr<<endl;
    // int k=0;
    vector<pair<int,int>> ans;
    while(!q.empty()){
        auto [dis,id1,id2]=q.top();
        q.pop();
        if(del[id1]||del[id2])continue;
        del[id1]=del[id2]=1;
        // cerr<<"id1="<<id1<<" "<<"id2="<<id2<<endl;
        int l=lb[id1][0],r=lb[id2][1];
        lb[l][1]=r,lb[r][0]=l;
        // now=1;
        // while(del[now])now++;
        // cerr<<"test"<<++k<<": ";
        // while(now&&!del[now]){
        //     cerr<<"now="<<now<<" ";
        //     now=lb[now][1];
        // }
        // cerr<<endl;
        ans.push_back({id1,id2});
        if(l&&r&&t[l].g!=t[r].g)q.push({llabs(t[l].a-t[r].a),l,r});
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<(int)ans.size()-1;i++){
        cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }
    cout<<ans.back().first<<" "<<ans.back().second;
    return 0;
}