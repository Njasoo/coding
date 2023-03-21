#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define N 1000005
#define M 500005
#define MN 1000000
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

long long v1[N],l1[N],v2[N],l2[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long L,N1,N2;
    cin>>L>>N1>>N2;
    for(int i=1;i<=N1;i++) cin>>v1[i]>>l1[i];
    for(int i=1;i<=N2;i++) cin>>v2[i]>>l2[i];
    int p1=1,p2=1;
    long long r1=l1[p1],r2=l2[p2]; // 第一个右端点
    long long pre_r1=0,pre_r2=0;
    long long ans=0;
    while(p1<=N1 && p2<=N2)
    {
        if(v1[p1]==v2[p2])
        {
            ans+=max(0LL,min(r1,r2)-max(pre_r1,pre_r2));
        }
        if(r1<r2)
        {
            p1++;
            pre_r1=r1; // 更新前一个右端点
            r1+=l1[p1]; // 更新当前右端点
        }
        else if(r1>r2)
        {
            p2++;
            pre_r2=r2;
            r2+=l2[p2];
        }
        else
        {
            p1++;
            p2++;
            pre_r1=r1;
            pre_r2=r2;
            r1+=l1[p1];
            r2+=l2[p2];
        }
    }
    cout<<ans<<'\n';
    return 0;
}