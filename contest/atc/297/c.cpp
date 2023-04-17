#include<iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            if(s[j]=='T')
            {
                if(j+1>=m) continue;
                if(s[j+1]=='T')
                {
                    s[j]='P';
                    s[j+1]='C';
                    j++;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}