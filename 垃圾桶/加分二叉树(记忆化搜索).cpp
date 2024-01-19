#include<bits/stdc++.h>
using namespace std;
const int N=35;
long long d[N],dp[N][N][N];//dp[l][r][u]：[l,r]区间上，u作为根节点的最大加分
int n;
long long solve(int l,int r,int u){
    assert(l>=1&&l<=n&&r>=1&&r<=n);
    if(dp[l][r][u]!=-1)return dp[l][r][u];
    if(l>r)return dp[l][r][u]=1;
    if(l==r){
        dp[l][r][u]=d[u];
        // cerr<<"l="<<l<<" "<<"r="<<r<<" u="<<u<<" dp[l][r][u]="<<dp[l][r][u]<<endl;
        return dp[l][r][u];
    }
    long long maxl=1,maxr=1;
    for(int i=l;i<=u-1;i++){
        maxl=max(maxl,solve(l,u-1,i));
    }
    for(int i=u+1;i<=r;i++){
        maxr=max(maxr,solve(u+1,r,i));
    }
    dp[l][r][u]=maxl*maxr+d[u];
    // cerr<<"l="<<l<<" "<<"r="<<r<<" u="<<u<<" dp[l][r][u]="<<dp[l][r][u]<<endl;
    return dp[l][r][u];
}
void print_ans(int l,int r){
    if(l>r)return;
    int root=-1;
    long long mx=0;
    for(int i=l;i<=r;i++){
        if(dp[l][r][i]>mx){
            mx=dp[l][r][i];
            root=i;
        }
    }
    cout<<root<<" ";
    print_ans(l,root-1);
    print_ans(root+1,r);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i];
    long long ans=0;
    // ans=solve(1,5,3);
    for(int i=1;i<=n;i++){
        ans=max(ans,solve(1,n,i));
    }
    cout<<ans<<'\n';
    print_ans(1,n);
    cout<<'\n';
    return 0;
}