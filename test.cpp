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

int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--)
    {
        int n;
        scanf("%d", &n);
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        int l = 1, r = n;
        while (l <= r)
        {
            mid = (l + r) / 2;
            
        }
    }
    return 0;
}