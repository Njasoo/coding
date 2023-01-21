#include<bits/stdc++.h>
using namespace std;
int n,a[5005];
bool check(int m)
{
    if(m<3)return 0;
    map<int,int> hs;
    for(int i=1;i<=n;i++)
    {
        hs[a[i]%m]++;
        if(hs[a[i]%m]>n-hs[a[i]%m])return 1;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int tt=100;
    mt19937 rng(time(0));
    while(tt--)
    {
        int x=a[rng()%n+1];
        int y=a[rng()%n+1];
        int z=abs(x-y);
        if(z==0)continue;
        for(int i=1;i*i<=z;i++)
        {
            if(z%i==0)
            {
                if(check(i))
                {
                    printf("%d\n",i);
                    return 0;
                }
                if(check(z/i))
                {
                    printf("%d\n",z/i);
                    return 0;
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}