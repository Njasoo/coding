#include <bits/stdc++.h>
using namespace std;
long long sum0[200005],sum1[200005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        int n=s.size();
        s=' '+s;
        for(int i=1;i<=n;i++)
        {
            sum0[i]=sum0[i-1]+(s[i]=='0');
            sum1[i]=sum1[i-1]+(s[i]=='1');
        }
        int ans=sum1[n];
        for(int i=1;i<=n;i++)
        {
            int l=i,r=n;
            while(l<=r)
            {
                int mid=(l+r)/2;
                //1~i-1,mid+1~n移除
                int removed1=sum1[i-1]+sum1[n]-sum1[mid];
                //i~mid剩下
                int remain0=sum0[mid]-sum0[i-1];
                int cnt=max(remain0,removed1);
                ans=min(ans,cnt);
                if(removed1>remain0)l=mid+1;
                else r=mid-1;
            }
        }
        cout<<ans<<'\n';
    }   
    return 0;
}