#include<iostream>
using namespace std;
int main()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
    }
    return 0;
}