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
ll f[50],MOD=(ll)pow(2,31);

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    f[0]=0,f[1]=f[2]=1;
    for(int i=3;i<=n;i++)
    {
        f[i]=(f[i-1]+f[i-2])%MOD;
    }
    cout<<f[n]<<"=";
    int x=0;
    for(int i=2;i<=f[n];i++)
    {
        while(f[n]%i==0)
        {
            x++;
            if(x==1)
            {
                cout<<i;
            }
            else
            {
                cout<<"*"<<i;
            }
            f[n]/=i;
        }
    }
    cout<<endl;
    return 0;
}