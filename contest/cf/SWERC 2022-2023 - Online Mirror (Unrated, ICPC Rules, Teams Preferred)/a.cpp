#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int MOD=998244353;
long long a[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        a[n+1]=1440;
        int cnt=0;
        for(int i=1;i<=n+1;i++)
        {
            cnt+=(a[i]-a[i-1])/120;
        }
        if(cnt>=2)cout<<"YES\n";
        else cout<<"NO\n";
    }   
    return 0;
}