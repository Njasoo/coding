#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int MOD=998244353;
long long a[1000005],b[1000005],p[1000005];
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
            p[a[i]]=i;
        }
        int len=1;
        for(int i=1;i<=n;i++)cin>>b[i];
        for(int i=n;i>=2;i--)
        {
            if(p[b[i]]>p[b[i-1]])len++;
            else break;
        }
        // cerr<<"len:"<<len<<endl;
        cout<<n-len<<'\n';
    }   
    return 0;
}