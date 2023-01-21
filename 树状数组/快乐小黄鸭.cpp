#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

#define int long long

struct node{
    int val,id;
}h[200005];
int ch[200005],t[200005];
int n,a;

bool cmp(node i,node j){
    if(i.val==j.val)return i.id>j.id;
    return i.val>j.val;
}

void add(int x){
    while(x<=n){
        t[x]++;
        x+=x&-x;
    }
}

int sum(int x){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=x&-x;
    }
    return ans;
}

signed main(){
    cin>>n>>a;
    map<int,int> pos;
    for(int i=1;i<=n;i++){
        cin>>h[i].val;
        h[i].id=i;
        pos[h[i].val]=i;
    }
    if(a==-1){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++){
        ch[i]=h[i].val;
    }
    sort(h+1,h+1+n,cmp);
    int cnt=0;
    for(int i=1;i<=n;i++){
        add(h[i].id);
        cnt+=sum(h[i].id-1);
    }
    int cnt2=0;
    for(int i=1;i<=n;i++){
        if(ch[i]==i){
            continue;
        }
        int temp=ch[i];
        swap(ch[i],ch[pos[i]]);
        swap(pos[temp],pos[i]);
        cnt2++;
    }
    cout<<(cnt-cnt2)/2<<'\n';
    return 0;
}