#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s;
        cin>>s;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!='0')cnt++;
        }
        cout<<cnt<<'\n';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')continue;
            string temp="";
            temp+=s[i];
            string temp2(s.size()-1-i,'0');
            temp+=temp2;
            cout<<temp<<" ";
        }
        cout<<'\n';
    }
    return 0;
}