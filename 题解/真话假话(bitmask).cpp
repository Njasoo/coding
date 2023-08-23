#include <bits/stdc++.h>
using namespace std;
const int N=25;
int f[N],a[N],b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
    }
    memset(f,-1,sizeof(-1));
    for(int mask=0;mask<(1<<n);mask++)
    {
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            f[i]=(mask>>(n-1-i))&1;
        }
        for(int i=0;i<n;i++)
        {
            if(f[i] && f[a[i]]!=b[i])
            {
                flag=0;
                break;
            }
            if(!f[i] && f[a[i]]==b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            for(int i=0;i<n;i++)
            {
                cout<<((mask>>(n-1-i)&1))<<" ";
            }
            cout<<'\n';
            break;
        }
    }
    return 0;
}