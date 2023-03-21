#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define N 1000005
#define M 500005
#define MN 100000
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

int main()
{
    int n=5;
    double sum=0;
    double l_bar=67.27/60;
    for(int i=1; i<=n; i++)
    {
        double l;
        scanf("%lf", &l);
        l/=60;
        sum+=(l-l_bar)*(l-l_bar);
    }
    double ans=sqrt(sum/20.0);
    printf("%.20lf\n", ans);
    return 0;
}