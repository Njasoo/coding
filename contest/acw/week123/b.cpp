#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
ll d[N],sum[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        d[l]++,d[r+1]--;
    }   
    for(int i=1;i<=200000;i++){
        d[i]+=d[i-1];
        sum[i]=sum[i-1]+(d[i]>=k);
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<sum[b]-sum[a-1]<<'\n';
    }
    return 0;
}