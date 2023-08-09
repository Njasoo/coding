#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl

const int N=55;
int a[N];

void solve()
{
    int n;
    cin>>n;
    int maxa=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]<a[i])
            {
                maxa=max(maxa,a[i]);
                break;
            }
        }
    }
    if(is_sorted(a+1,a+1+n))cout<<"0\n";
    else cout<<maxa<<'\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}