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
// lalala~~~
/*
*/
int dp[1005][1005];
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int l=0,r=0,mx=0;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(s[i]==s[j]&&(j-i<=1||dp[i+1][j-1]))
            {
                dp[i][j]=1;
            }
            if(dp[i][j]&&j-i+1>mx)
            {
                mx=j-i+1;
                l=i;
                r=j;
            }
        }
    }      
    cout<<s.substr(l,r-l+1)<<endl;
    return 0;
}