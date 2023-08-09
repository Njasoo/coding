#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl

const int N=1e6+5;
int a[N],b[N],pre[N],aft[N],cnt[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        cnt[a[i]]++,cnt[b[i]]++;
        pre[b[i]]=a[i];
        aft[a[i]]=b[i];
    }
    int first,second=aft[0];
    for(int i=1;i<=n;i++)
    {
        if(cnt[a[i]]==1)
        {
            first=a[i];
            break;
        }
    }
    while(first&&second)
    {
        cout<<first<<" "<<second<<" ";
        first=aft[first];
        second=aft[second];
    }
    if(n%2)cout<<first;
    return 0;
}