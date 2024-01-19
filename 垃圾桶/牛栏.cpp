#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=5e4+5;
struct Node{
    int l,r,id;
}t[N];
bool cmp(Node i,Node j){
    return i.l<j.l;
}
int ans[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].l>>t[i].r;
        t[i].id=i;
    }
    sort(t+1,t+1+n,cmp);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;//（结束时间，牛栏编号）
    for(int i=1;i<=n;i++){
        // cerr<<"hello"<<endl;
        if(q.empty()||t[i].l<=q.top().first){//如果比最早结束的牛栏都早，那其他牛栏也不可能
            pair<int,int> xin_niulan;
            xin_niulan.first=t[i].r;
            xin_niulan.second=q.size()+1;//牛栏一旦创建，永不消失，所以直接用size做编号
            q.push(xin_niulan);
            ans[t[i].id]=xin_niulan.second;
        }else{
            pair<int,int> zuizao_niulan=q.top();
            q.pop();
            zuizao_niulan.first=t[i].r;
            q.push(zuizao_niulan);
            ans[t[i].id]=zuizao_niulan.second;
        }
    }
    cout<<q.size()<<endl;
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}