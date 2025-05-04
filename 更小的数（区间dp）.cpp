#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

const int N=5005;
bool dp[N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    int n=s.size();
    s=' '+s;
    // db(int('0')),db(int('2')),el;
    for(int len=2;len<=n;len++){
        for(int i=1;i+len-1<=n;i++){
            int j=i+len-1;
            if(s[j]<s[i]){
                dp[i][j]=1;
            }else if(s[j]>s[i]){
            }else{
                dp[i][j]=dp[i+1][j-1];
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans+=dp[i][j];
        }
    }
    cout<<ans<<'\n';
    return 0;
}