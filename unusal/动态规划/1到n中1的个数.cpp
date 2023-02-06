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
int ans[1000005];
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;  
    for(int i=1;i<=n;i++)
    {
        ans[i]=ans[i>>1]+(i&1);
    }    
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}