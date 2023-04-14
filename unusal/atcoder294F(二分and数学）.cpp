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

long long n,m,k;
double a[N][2],b[N][2];
double ta[N],tb[N];

//找到一个排名为k+1的但是最接近排名为k的浓度，也就是排名为k+1但是浓度最大的C
//或者找到一个排名为k，但是浓度最小的C

bool check(double C)
{
    for(int i=1;i<=n;i++) ta[i]=(1-C)*a[i][0]-C*a[i][1];
    for(int i=1;i<=m;i++) tb[i]=(C-1)*b[i][0]+C*b[i][1];
    sort(ta+1,ta+1+n);//记得排序
    sort(tb+1,tb+1+m);
    long long cnt=0;//开long long不然会爆
    for(int i=1;i<=n;i++)
    {
        int l=1,r=m+1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(ta[i]<=tb[mid]) r=mid;
            else l=mid+1;
        }
        cnt+=r-1;//r为第一大于等于ta[i]的坐标，则前面的r-1都满足ta[i]>ta[j]
    }
    cnt++;//加了1才是浓度C的排名
    return cnt>k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
    for(int i=1;i<=m;i++) cin>>b[i][0]>>b[i][1];
    double l=0,r=1;
    while(r-l>1e-15)
    {
        double mid=(l+r)/2;
        if(check(mid)) l=mid;
        else r=mid;
    }
    cout<<fixed<<setprecision(12)<<r*100<<'\n';
    return 0;
}