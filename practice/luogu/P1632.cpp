#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int MOD=998244353;
long long x[1000005],y[1000005];
long long dis(long long x0,long long y0,long long x1,long long y1){
    return llabs(x0-x1)+llabs(y0-y1);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i];
    }
    for(int k=1;k<=n;k++){
        if(k==1){
            cout<<0<<'\n';
            continue;
        }
        long long ans=1e18;
        for(long long mask=1;mask<(1<<(n+1))-1;mask+=2){
            if(__builtin_popcount(mask)!=k)continue;
            for(int i=1;i<=n;i++){
                if(mask>>i&1)
            }
        }
    }
    return 0;
}