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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f

long long fac[N],inv[N];

long long power(long long u,long long v)
{
    long long res=1;
    while(v)
    {
        if(v%2) res=res*u%MOD;
        u=u*u%MOD;
        v/=2;
    }
    return res;
}

void init()
{
    fac[0]=1;
    for(int i=1;i<=MN;i++) fac[i]=fac[i-1]*i%MOD;
    inv[MN]=power(fac[MN],MOD-2);
    for(int i=MN-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%MOD;
}

long long C(int n,int m)
{
    return (fac[n]*inv[m]%MOD)*inv[n-m]%MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int tt;
    cin>>tt;
    while(tt--)
    {
        int n,m;
        cin>>n>>m;
        if(n==m)
        {
            cout<<"1\n";
            continue;
        }
        long long ans=C(n,m)*fac[n-m-1]%MOD;
        cout<<ans<<'\n';
    }   
    return 0;
}