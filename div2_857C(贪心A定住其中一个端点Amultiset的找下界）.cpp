#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl
//按照a排序
//如果ai是选择的最大的a，那么
//则i+1~n都是选择b
//1~i-1随便选,选一个最接近ai的b
//i+1~n可以线段树
//用multiset寻找第一个大于等于a[i]的数，还有他的前一个数,这两个刚好夹着a[i]
//最小差值只会在这两个中间产生
//三个b值可以选,max2,1~i-1的那两个数,max2是一定会选到的，剩余两个数都可以随意选
const int N=5e5+5;
long long tree[N<<2];
struct node{
    long long a,b;
}t[N];

void build(int id,int l,int r){
    if(l==r){
        tree[id]=t[l].b;
        return;
    }
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    tree[id]=max(tree[id<<1],tree[id<<1|1]);
}
long long query(int id,int l,int r,int s,int e){
    if(l==s && r==e){
        return tree[id];
    }
    int mid=(l+r)>>1;
    if(e<=mid){
        return query(id<<1,l,mid,s,e);
    }else if(s>mid){
        return query(id<<1|1,mid+1,r,s,e);
    }else{
        return max(query(id<<1,l,mid,s,mid),query(id<<1|1,mid+1,r,mid+1,e));
    }
}

bool cmp(node i,node j){
    return i.a<j.a;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b;
    }
    sort(t+1,t+1+n,cmp);
    build(1,1,n);
    long long ans=1e18;
    multiset<long long> ms;
    //i==1的情况
    long long max_ip1_to_n=query(1,1,n,2,n);
    // db(max_ip1_to_n);
    ans=min(ans,abs(max_ip1_to_n-t[1].a));

    for(int i=2;i<n;i++){

        // db(i);

        long long max2=query(1,1,n,i+1,n);
        long long max1=query(1,1,n,1,i-1);
        // db(max2);
        // db(max1);
        ms.insert(t[i-1].b);
        ans=min(ans,abs(max2-t[i].a));
        if(max2>=max1){//最大的b一定出现在后半段，没有必要再从前面找
            continue;
        }

        auto it=ms.lower_bound(t[i].a);
        if(it!=ms.end()){
            // if(i==4){
            //     db(t[i].a);
            //     db(*it);
            //     for(auto x : ms){
            //         cerr<<x<<" ";
            //     }
            //     cerr<<endl;
            // }
            // db(*it);
            if(*it>=max2){
                ans=min(ans,abs(*it-t[i].a));
            }
        }
        // else{
        //     cerr<<"hello1"<<endl;
        // }
        if(it!=ms.begin()){
            // if(i==4){
            //     db(*prev(it));
            //     // for(auto x:ms){
            //     //     cerr<<x<<" ";
            //     // }
            //     // cerr<<endl;
            // }
            // db(*prev(it));
            if(*prev(it)>=max2){
                ans=min(ans,abs(*prev(it)-t[i].a));
            }
        }
        // else{
        //     cerr<<"hello2"<<endl;
        //     for(auto x:ms){
        //             cerr<<x<<" ";
        //         }
        //     cerr<<endl;
        // }
    }
    //i==n的情况
    ms.insert(t[n-1].b);
    // db(n);
    // for(auto x:ms){
    //     cerr<<x<<' ';
    // }
    // cerr<<endl;
    auto it=ms.lower_bound(t[n].a);
    if(it!=ms.end()){
        // db(*it);
        ans=min(ans,abs(*it-t[n].a));
    }
    if(it!=ms.begin()){
        it=prev(it);
        // db(*it);
        ans=min(ans,abs(*it-t[n].a));
    }
    cout<<ans<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--){
        solve();
    }   
    return 0;
}