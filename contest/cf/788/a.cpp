#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int a[1000005];
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
        int k=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {
                k++;
                a[i]=-a[i];
            }
        }
        for(int i=1;i<=k;i++)
        {
            a[i]=-a[i];
        }
        int c=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i+1])
            {
                c=0;
                break;
            }
        }
        if(c)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}