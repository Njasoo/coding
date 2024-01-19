#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int tr[N*2],n,temp[N*2];
int idx;
void add(int x,int k){
    while(x<=2*n){
        tr[x]+=k;
        x+=x&-x;
    }
}
int query(int x){
    int res=0;
    while(x){
        res+=tr[x];
        x-=x&-x;
    }
    return res;
}
struct Node{
    int a,b;
}t[N];
bool cmp(Node i,Node j){
    return i.b>j.b;
}
//当一个区间完全包含另一个区间，他们会打招呼,我们要计算这样的区间对数
//按照右端点排序，枚举区间，看当前区间左端点前面已经出现了多少个左端点
//计算包裹的数量和被包裹的数量应该是等价的，现在是计算被包裹，所以右端点从大到小排序
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        cin>>n;
        idx=0;
        for(int i=1;i<=n;i++){
            cin>>t[i].a>>t[i].b;
            //有正有负，所以需要离散化
            temp[++idx]=t[i].a;
            temp[++idx]=t[i].b;
        }
        sort(temp+1,temp+1+idx);
        for(int i=1;i<=n;i++){
            t[i].a=lower_bound(temp+1,temp+1+idx,t[i].a)-temp;
            t[i].b=lower_bound(temp+1,temp+1+idx,t[i].b)-temp;
        }
        sort(t+1,t+1+n,cmp);
        memset(tr,0,sizeof(tr));
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=query(t[i].a-1);
            add(t[i].a,1);
        }
        cout<<ans<<'\n';
    }
    return 0;
}