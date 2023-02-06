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
int my_compare(string s1,string s2)
{
    if(s1==s2)return 0;
    if(s1.size()==s2.size())
        if(s1>s2)return 1;
        else return -1;
    else
        if(s1.size()>s2.size())return 1;
        else return -1;
}
//hahaha!!!
int a[105];
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int ans=0;
    map<int,int>hs;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            hs[a[i]+a[j]]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(hs[a[i]])
        {
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}