#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<x<<endl;
const int N=2e5+5;
const long long INF=0x3f3f3f3f3f3f3f3f;
long long n,m,s;//资料类型定义成int，debug了半天，woc
long long w[N],v[N],l[N],r[N],sum1[N],sum2[N];
long long check(long long mid){
    for(int i=1;i<=n;i++){
        sum1[i]=sum1[i-1]+(w[i]>=mid);
        sum2[i]=sum2[i-1]+(w[i]>=mid)*v[i];
    }
    long long y=0;
    for(int i=1;i<=m;i++){
        y+=(sum1[r[i]]-sum1[l[i]-1])*(sum2[r[i]]-sum2[l[i]-1]);
    }
    return y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
    }
    long long ans=INF,L=0,R=1e6;
    while(L<=R){
        long long mid=(L+R)>>1;
        long long y=check(mid);
        if(y>s) L=mid+1;
        else R=mid-1;
        if(llabs(y-s)<ans) ans=llabs(y-s);
    }
    cout<<ans<<'\n';
    return 0;
}