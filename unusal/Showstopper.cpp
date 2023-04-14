#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

#define db(x) cerr<<#x<<"="<<(x)<<endl
#define N 1000005
#define M 500005
#define MN 1000000
#define LOG 20
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

int a[N],b[N];

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
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        if(a[n]>b[n]) swap(a[n],b[n]);
        for(int i=1;i<=n;i++)
        {
            if(b[i]<a[i] && b[i]<=a[n]) swap(a[i],b[i]);
        }
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>a[n])
            {
                flag=0;
                break;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(b[i]>b[n])
            {
                flag=0;
                break;
            }
        }
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    }   
    return 0;
}