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
/*
若第一个值是最小值且不为零，那么不管A选择哪个a[i]来交换，都比原来的a[1]大
0就看做最小值就行       

所以到了B手上的时候，a1一定不为零，B需要干的就是把数组中最小值扔回去给A
那么第一个面对a1==0的局面的人一定是A

所以如果a1等于最小值，则B胜
反之A胜
*/
long long a[N];

int main()
{
    int tt;
    scanf("%d", &tt);
    while(tt--)
    {
        int n;
        scanf("%d", &n);
        long long mn=INF;
        for(int i=1; i<=n; i++)
        {
            scanf("%lld", &a[i]);
            mn=min(mn, a[i]);
        }
        if(mn==a[1]) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}