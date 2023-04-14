#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define N 1000005
#define M 500005
#define MN 100000
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

long long sum[N];

long long ask(int l,int r)
{
    int len=r-l+1;
    cout<<"? "<<len<<" ";
    for(int i=l;i<=r;i++) cout<<i<<" ";
    cout<<endl;
    long long res;
    cin>>res;
    return res;
}

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
            int a;
            cin>>a;
            sum[i]=sum[i-1]+a;
        }
        int l=1,r=n;
        int mid=-1;
        while(l<r)
        {
            mid=(l+r)/2;
            long long left=ask(l,mid);
            if(sum[mid]-sum[l-1]<left) r=mid;
            else l=mid+1;
            // cerr<<"l:"<<l<<" "<<"r:"<<r<<endl;
        }
        mid=(l+r)/2;
        cout<<"! "<<mid<<endl;
    }   
    return 0;
}