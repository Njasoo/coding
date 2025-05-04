#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=1e6+5;
ll a[2][N],sum[2][N],pregx[N],suffgx[N],premx[2][N],suffmx[2][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int j=0;j<=n+1;j++){
            pregx[j]=-1e18;
            suffgx[j]=-1e18;
            premx[0][j]=premx[1][j]=-1e18;
            suffmx[0][j]=suffmx[1][j]=-1e18;
        }
        for(int i=1;i<=2;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                sum[i-1][j]=sum[i-1][j-1]+a[i][j];
                // db(i-1),db(j),db(sum[0][0]),db(sum[i-1][j]),el;
            }
        }
        //-a[0][u]+a[1][u]
        //-a[1][v]+a[0][v]
        for(int i=1;i<=n;i++){
            premx[0][i]=max(premx[0][i-1],a[1][i]);
            premx[1][i]=max(premx[1][i-1],a[2][i]);
        }
        for(int i=n;i>=1;i--){
            suffmx[0][i]=max(suffmx[0][i+1],a[1][i]);
            suffmx[1][i]=max(suffmx[1][i+1],a[2][i]);
//            db(i),db(suffmx[0][i]),el;
        }
        for(int j=1;j<n;j++){
            ll gx=a[1][j]-a[0][j];
            pregx[j]=max(pregx[j-1],gx);
        }
        for(int j=n;j>=2;j--){
            ll gx=a[0][j]-a[1][j];
            suffgx[j]=max(suffgx[j+1],gx);
        }
        ll ans=-1e18;
        for(int j=1;j<=n;j++){
//            db(j),db(sum[0][j-1]),db(sum[1][n]-sum[1][j]),el;
            ll cnt=sum[0][j-1]+a[1][j]+a[2][j]+(sum[1][n]-sum[1][j]);
            ans=max(ans,cnt);
            if(j-1>=1 && j+1<=n){
                ans=max(ans,cnt+pregx[j-1]+suffgx[j+1]);
            }
            if(j+1<=n){
            	ll cnt2=cnt-a[1][j]+suffmx[0][j+1];
            	ans=max(ans,cnt2);
			}
            // if(j==1) db(cnt2),db(suffmx[0][j+1]),el;
            if(j-1>=1){
            	ll cnt3=cnt-a[2][j]+premx[1][j-1];
            	ans=max(ans,cnt3);
			}
        }
        cout<<ans<<"\n";
    }
    return 0;
}
