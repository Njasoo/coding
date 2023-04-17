#include<iostream>
using namespace std;

long long t[105];

int main()
{
    string s;
    cin>>s;
    int posb1=-1,posb2=-1;
    int posr1=-1,posr2=-1;
    int posk=-1;
    s=' '+s;
    for(int i=1;i<=8;i++)
    {
        if(s[i]=='B' && posb1==-1)
        {
            posb1=i;
            continue;
        }
        if(s[i]=='B' && posb2==-1)
        {
            posb2=i;
            continue;
        }
        if(s[i]=='R' && posr1==-1)
        {
            posr1=i;
            continue;
        }
        if(s[i]=='R' && posr2==-1)
        {
            posr2=i;
            continue;
        }
        if(s[i]=='K')
        {
            posk=i;
        }
    }
    if(posk>posr1 && posk<posr2 && (posb1%2 != posb2%2)) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}