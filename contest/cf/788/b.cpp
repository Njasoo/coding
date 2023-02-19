#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int tag[1000005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=" "+s;
        for(int i=0;i<26;i++)tag[i]=0;
        int k;
        cin>>k;
        for(int i=1;i<=k;i++)
        {
            char ch;
            cin>>ch;
            tag[ch-'a']=1;
        }
        int pre=1,ans=0;
        for(int i=1;i<=n;i++)
        {
            if(tag[s[i]-'a'])
            {
                ans=max(ans,i-pre);
                pre=i;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}