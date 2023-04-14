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

int a[N];

void solve()
{
    int n,k;
    cin>>n>>k;
    if(n==2 && k==2)
    {
        cout<<"-1 2\n";
        return;
    }
    memset(a,0,sizeof(a));
    int pre=-1;
    while(k>0)
    {
        int len=0;
        while(len*(len+1)<2*k) len++;
        if(len*(len+1)>2*k) len--;
        for(int i=pre+2;i<=pre+1+len;i++) a[i]=1;
        pre=pre+len+1;
        k-=len*(len+1)/2;
    }
    for(int i=1;i<=n;i++) if(!a[i]) a[i]=-1000;
    for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--) solve();   
    return 0;
}