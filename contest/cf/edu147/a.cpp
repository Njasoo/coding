#include<iostream>
using namespace std;
int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        long long ans=1;
        if(s[0]=='0')
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='?')ans*=10-(i==0);
        }
        cout<<ans<<endl;
    }
    return 0;
}