#include <bits/stdc++.h>

using namespace std;
using i64=long long;
using u64=unsigned long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

/*
1 3 2 4
k=2

从头开始找k个：7

3 1 2 4
猜想：顺序无所谓

考虑长度为k的窗口，窗口包含0的话是无法进行任何操作的，每次窗口需要移动到当前窗口内最后一个0的位置的后面
也就是每次都移动到最后一个最小的数的后面
*/

const int N=1e6+5,LOG=21;
int st[N][LOG],a[N],n,lg[N],k;
struct Node{
    int tag,val;
}t[N*4];

namespace seg {
    void build(int id, int left, int right) {
      t[id].tag = 0;
      if (left == right) {
          t[id].val = a[left];
          return;
      }
      int mid = (left + right) >> 1;
      build(id << 1, left, mid);
      build(id << 1 | 1, mid + 1, right);
      // t[id].val = t[id << 1].val + t[id << 1 | 1].val;
      t[id].val=min(t[id<<1].val,t[id<<1|1].val);
    }

    void push_down(int id) {
      t[id << 1].tag += t[id].tag;
      t[id << 1 | 1].tag += t[id].tag;
      t[id].tag = 0;
    }

    void update(int id, int left, int right, int s, int e, long long k) {
      if (e < left || s > right) {
          return;
      }
      if (s <= left && right <= e) {
          t[id].tag += k;
          return;
      }
      push_down(id);
      int mid = (left + right) >> 1;
      update(id << 1, left, mid, s, e, k);
      update(id << 1 | 1, mid + 1, right, s, e, k);
      t[id].val = min(t[id << 1].val + t[id << 1].tag,
                  t[id << 1 | 1].val + t[id << 1 | 1].tag);
    }

    long long query(int id, int left, int right, int s, int e) {
      if (e < left || s > right) {
          return 1e9;
      }
      if (s <= left && right <= e) {
          return t[id].val + t[id].tag;
      }
      push_down(id);
      int mid = (left + right) >> 1;
      long long res = min(query(id << 1, left, mid, s, e),
                      query(id << 1 | 1, mid + 1, right, s, e));
      t[id].val = min(t[id << 1].val + t[id << 1].tag,
                  t[id << 1 | 1].val + t[id << 1 | 1].tag);
      return res;
    }
}
using namespace seg;


void build(){
    for(int i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
    }
    for(int i=1;i<=n;i++){
        st[i][0]=a[i];
    }
    for(int j=1;j<LOG;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}

// int qry(int l,int r){
//     int b=lg[r-l+1];
//     return min(st[l][b],st[r-(1<<b)+1][b]);
// }

int find_p(int l,int r,int v){
    int lo=l,hi=r;
    while(lo<hi){
        int mid=(lo+hi)/2;
        if(query(1,1,n,mid+1,hi)==v){
            lo=mid+1;
        }
        else hi=mid;
    }
    return hi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    i64 ans=0;
    for(int i=1;i+k-1<=n;){
        int j=i+k-1;
        // int mn=qry(i,j);
        int mn=query(1,1,n,i,j);
        // d[i]-=mn;
        // d[j+1]+=mn;
        // db(i),db(j),db(mn),el;
        if(mn>0){
            update(1,1,n,i,j,-mn);
            ans+=mn;
        }
        int p=find_p(i,j,0);
        // db(p),el;
        i=p+1;
    }
    for(int i=1;i<=n;i++){
        int tmp=query(1,1,n,i,i);
        // db(tmp);
        ans+=tmp;
    }
    // el;
    cout<<ans<<'\n';
    return 0;
}