#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5+5;
int pref[N];
int sum[N][30][2];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pref[i]=pref[i-1]^a;
        for(int j=0;j<30;j++){
            sum[i][j][0]=sum[i-1][j][0];
            sum[i][j][1]=sum[i-1][j][1];
            if(pref[i]>>j&1){
                sum[i][j][1]++;
            }else{
                sum[i][j][0]++;
            }
        }
    }
    long long ans=0;
    for(int j=0;j<30;j++){
        for(int i=1;i<=n;i++){
            if(pref[i-1]>>j&1){
                ans=(ans+(1<<j)*(sum[n][j][0]-sum[i-1][j][0]));
            }else{
                ans=(ans+(1<<j)*(sum[n][j][1]-sum[i-1][j][1]));
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}