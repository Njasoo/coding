#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    string mark="-1";
    int cnt=0;
    bool zero=0;
    for(int i=1;i<=n;i++)
    {
        string num;
        cin>>num;
        if(num=="0")
        {
            zero=1;
            continue;
        }
        if(num[0]=='1')
        {
            bool check=1;
            for(int j=1;j<num.size();j++)
            {
                if(num[j]!='0')
                {
                    check=0;
                    break;
                }
            }
            if(!check)
            {
                mark=num;
            }
            else
            {
                cnt+=num.size()-1;
            }
        }
        else
        {
            mark=num;
        }
    }
    if(zero)
    {
        cout<<"0\n";
    }
    else if(mark!="-1")
    {
        cout<<mark;
        for(int i=1;i<=cnt;i++) cout<<"0";
        cout<<endl;
    }
    else
    {
        cout<<"1";
        for(int i=1;i<=cnt;i++)cout<<"0";
        cout<<endl;
    }
    return 0;
}