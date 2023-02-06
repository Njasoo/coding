#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define endl '\n'
#define vt vector
#define pb push_back
#define sz(x) (int)x.size()
//lalala~~~
/*
*/
int my_compare(string s1,string s2){
    if(s1==s2)return 0;
    if(s1.size()==s2.size())
        if(s1>s2)return 1;
        else return -1;
    else
        if(s1.size()>s2.size())return 1;
        else return -1;
}
//hahaha!!!
int dp[55][55];
//dp[i][j]:第i轮传到j的方案数
//dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];传到j的方案数等于上一轮传到j的左边和右边的方案数总和
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    dp[0][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j==1){
                dp[i][1]=dp[i-1][n]+dp[i-1][2];
            }
            else if(j==n){
                dp[i][n]=dp[i-1][n-1]+dp[i-1][1];
            }
            else{
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1];
            }
        }
    }
    cout<<dp[m][1]<<endl;
    return 0;
}