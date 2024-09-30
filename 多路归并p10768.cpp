#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<cassert>
#include<map>
#include<unordered_set>
#include<queue>
using namespace std;

const int N=1e6+5;
long long a[N];
pair<long long,int> t[N];
int n,m;
int aft[N],bef[N];
unordered_set<unsigned long long> st;
struct Node{
    long long w;
    int u,v;
    bool moveR;

    bool operator<(const Node& rhs)const{
        return w>rhs.w;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    vector<pair<long long,int>> pos,neg;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[i]={a[i],i};
        if(t[i].first>=0)pos.push_back(t[i]);
        else neg.push_back(t[i]);
    }
    if(n<=1){
        cout<<"0\n";
        return 0;
    }
    sort(t+1,t+1+n);
    aft[t[1].second]=t[2].second;
    bef[t[n].second]=t[n-1].second;
    for(int i=2;i<n;i++){
        aft[t[i].second]=t[i+1].second;
        bef[t[i].second]=t[i-1].second;
    }
    sort(pos.begin(),pos.end(),greater<pair<long long,int>>());
    sort(neg.begin(),neg.end());
    vector<pair<int,int>> e;
    long long ans=0;
    if(!pos.empty()&&!neg.empty()){
        for(int j=0;j<(int)neg.size();j++){
            int x=pos[0].second,y=neg[j].second;
            if(x>y)swap(x,y);
            st.insert((unsigned long long)x<<32|y);
            e.emplace_back(x,y);
            ans+=a[x]*a[y];
        }
        for(int i=1;i<(int)pos.size();i++){
            int x=neg[0].second,y=pos[i].second;
            if(x>y)swap(x,y);
            st.insert((unsigned long long)x<<32|y);
            e.emplace_back(x,y);
            ans+=a[x]*a[y];
        }
    }else if(!pos.empty()){
        for(int i=0;i<(int)pos.size()-1;i++){
            int x=pos[i].second,y=pos.back().second;
            if(x>y)swap(x,y);
            st.insert((unsigned long long)x<<32|y);
            e.emplace_back(x,y);
            ans+=a[x]*a[y];
        }
    }else{
        for(int i=0;i<(int)neg.size()-1;i++){
            int x=neg[i].second,y=neg.back().second;
            if(x>y)swap(x,y);
            st.insert((unsigned long long)x<<32|y);
            e.emplace_back(x,y);
            ans+=a[x]*a[y];
        }
    }
    priority_queue<Node> q;
    for(int i=1;i<n;i++){
        if(t[i].first>=0){
            int x=t[i].second,y=t[1].second;
            if(i==1)q.push({a[x]*a[t[2].second],x,t[2].second,true});
            else q.push({a[x]*a[y],x,y,true});
        }else{
            int x=t[i].second,y=t[n].second;
            if(i==n)q.push({a[x]*a[t[n-1].second],x,t[n-1].second,false});
            else q.push({a[x]*a[y],x,y,false});
        }
    }
    while((int)e.size()<m){
        Node node=q.top();
        q.pop();
        long long w=node.w;
        int u=node.u,v=node.v;
        bool moveR=node.moveR;
        unsigned long long x=u,y=v;
        // cerr<<"(w,u,v):"<<w<<" "<<u<<" "<<v<<" "<<endl;
        if(x>y)swap(x,y);
        if(st.find(x<<32|y)==st.end()){
            st.insert(x<<32|y);
            ans+=w;
            e.emplace_back(x,y);
        }
        if(moveR){
            v=aft[v];
            if(v==u)v=aft[v];
            if(!v)continue;
        }else{
            v=bef[v];
            if(v==u)v=bef[v];
            if(!v)continue;
        }
        q.push({a[u]*a[v],u,v,moveR});
    }
    cout<<ans<<'\n';
    for(auto [u,v]:e){
        cout<<u<<" "<<v<<'\n';
    }
    return 0;
}