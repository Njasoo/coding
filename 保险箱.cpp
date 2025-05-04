#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl
#define ts cerr<<"hi "
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
#define chkmax(a,b) a=a>(b)?a:(b)
#define chkmin(a,b) a=a<(b)?a:(b)

template<class T>
void dbarr(T arr[],int l,int r){
    for(int i=l;i<=r;i++){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

const int N=2e5+5;
ll dp[N][3];

ll calcsub(char a,char b){
    return a-'0'+1+'9'-b;
}

ll calcadd(char a,char b){
    return '9'-a+1+b-'0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string x,y;
    cin>>n>>x>>y;
    x=' '+x;
    y=' '+y;
    for(int i=1;i<=n+1;i++){
        dp[i][0]=dp[i][1]=dp[i][2]=1e18;
    }
    dp[n+1][1]=0;
    for(int i=n;i>=1;i--){
        chkmin(dp[i][0],dp[i+1][0]+calcsub(x[i],y[i])-1);
        chkmin(dp[i][0],dp[i+1][1]+calcsub(x[i],y[i]));
        chkmin(dp[i][0],dp[i+1][2]+calcsub(x[i],y[i])+1);
        chkmin(dp[i][2],dp[i+1][0]+calcadd(x[i],y[i])+1);
        chkmin(dp[i][2],dp[i+1][1]+calcadd(x[i],y[i]));
        chkmin(dp[i][2],dp[i+1][2]+calcadd(x[i],y[i])-1);
        int cnt=abs(x[i]-y[i]);
        chkmin(dp[i][1],dp[i+1][1]+cnt);
        if(x[i]>y[i]){
            chkmin(dp[i][1],dp[i+1][0]+cnt-1);
            chkmin(dp[i][1],dp[i+1][2]+cnt+1);
        }
        else if(x[i]<y[i]){
            chkmin(dp[i][1],dp[i+1][0]+cnt+1);
            chkmin(dp[i][1],dp[i+1][2]+cnt-1);
        }
        else{
            chkmin(dp[i][1],dp[i+1][0]+1);
            chkmin(dp[i][1],dp[i+1][2]+1);
        }
    }
    // for(int i=1;i<=n;i++){
    //     db(i),db(dp[i][0]),db(dp[i][1]),db(dp[i][2]),el;
    // }
    cout<<min({dp[1][0],dp[1][1],dp[1][2]})<<'\n';
    return 0;
}