#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define endl '\n'
const int MOD=998244353;
long long a[1000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x,n;
    cin>>x>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    if(a[1]!=1){
        cout<<-1<<endl;
    }else{
        long long ans=0;
        long long sum=0;
        for(int i=1;i<=x;i++){
            if(sum>=i)continue;
            long long l=1,r=n;
            long long pos=0;
            while(l<=r){
                long long mid=(l+r)/2;
                if(a[mid]>i){
                    r=mid-1;
                }else{
                    l=mid+1;
                    pos=mid;
                }
            }
            sum+=a[pos];
            ans++;
        }        
        cout<<ans<<endl;
    }
    return 0;
}