#include<iostream>

using namespace std;

string s;
int idx;

string func()
{
    // cerr<<"Hello"<<endl;
    string res="";
    while(idx<(int)s.size())
    {
        if(s[idx]=='[')
        {
            idx++;
            int num=0;
            while(isdigit(s[idx]))
            {
                num=num*10+s[idx]-'0';
                idx++;
            }
            string str=func();
            for(int i=1;i<=num;i++)
            {
                res+=str;
            }
        }
        if(s[idx]==']')
        {
            idx++;
            break;
        }
        if(isalpha(s[idx]))
        {
            res+=s[idx];
            idx++;
        }
    }
    return res;
}

int main()
{
    cin>>s;
    cout<<func()<<endl;
    return 0;
}