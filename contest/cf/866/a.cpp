#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int n=s.size();
        s=' '+s;
        if(n==1)
        {
            if(s[1]=='^')cout<<1<<endl;
            if(s[1]=='_')cout<<2<<endl;
            continue;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            int cnt=0;
            while(j<=n && s[j]=='_')
            {
                cnt++;
                j++;
            }
            i=j;
            if(cnt) ans+=cnt-1;
        }
        if(s[1]=='_')ans++;
        if(s[n]=='_')ans++;
        cout<<ans<<endl;
    }
    return 0;
}