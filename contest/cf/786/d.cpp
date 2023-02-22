#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int MOD=998244353;
long long a[1000005],c[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            c[i]=a[i];
        }
        sort(c+1,c+1+n);
    }   
    return 0;
}