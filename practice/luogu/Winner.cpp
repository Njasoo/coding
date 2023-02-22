#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MOD=998244353;
string s[10005];
long long x[10005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    map<string,long long> hs;
    map<string,long long> hs2;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>x[i];
        hs[s[i]]+=x[i];
    }   
    long long score=0;
    for(auto x:hs)
    {
        score=max(score,x.second);
    }
    for(int i=1;i<=n;i++)
    {
        hs2[s[i]]+=x[i];
        if(hs2[s[i]]>=score && hs[s[i]]==score)
        {
            cout<<s[i]<<'\n';
            return 0;
        }
    }
    return 0;
}