#include <bits/stdc++.h>

using namespace std;
using ll=long long;

#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
#define p_queue priority_queue
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N=2e5+5;
ll x[N],y[N];

ll dis(ll x1,ll y1,ll x2,ll y2){
    return llabs(x1-x2)+llabs(y1-y2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,k,a,b;
        cin>>n>>k>>a>>b;
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        if(a<=k&&b<=k){
            cout<<"0\n";
            continue;
        }
        ll mn_dis_from_major_to_b=1e18;
        for(int i=1;i<=k;i++){
            if(i==b)continue;
            mn_dis_from_major_to_b=min(mn_dis_from_major_to_b,dis(x[i],y[i],x[b],y[b]));
        }
        if(a<=k){
            cout<<mn_dis_from_major_to_b<<'\n';
            continue;
        }
        ll mn_dis_from_major_to_a=1e18;
        for(int i=1;i<=k;i++){
            if(i==a)continue;
            mn_dis_from_major_to_a=min(mn_dis_from_major_to_a,dis(x[i],y[i],x[a],y[a]));
        }
        if(b<=k){
            cout<<mn_dis_from_major_to_a<<'\n';
            continue;
        }
        ll dis_from_a_to_b=dis(x[a],y[a],x[b],y[b]);
        cout<<min(mn_dis_from_major_to_a+mn_dis_from_major_to_b,dis_from_a_to_b)<<'\n';
    }   
    return 0;
}