#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long a[1005],b[1005];
    long long num1,num2;
    char ch;
    long long cm=1;
    int k=0;
    while(cin>>num1>>ch>>num2)
    {
        k++;
        a[k]=num1;
        b[k]=num2;
        cm=cm*b[k]/__gcd(cm,b[k]);
    }
    long long sum=0;
    for(int i=1;i<=k;i++)
    {
        a[i]*=cm/b[i];
        sum+=a[i];
    }
    int w=0;
    if(sum<0)
    {
        sum=-sum;
        w=1;
    }
    if(w)
    {
        if(cm/__gcd(cm,sum)==1)
        {
            cout<<-sum/__gcd(cm,sum)<<endl;
            return 0;
        }
        cout<<-sum/__gcd(sum,cm)<<"/"<<cm/__gcd(cm,sum)<<endl;
    }
    else
    {
        if(cm/__gcd(cm,sum)==1)
        {
            cout<<sum/__gcd(cm,sum)<<endl;
            return 0;
        }
        cout<<sum/__gcd(sum,cm)<<"/"<<cm/__gcd(cm,sum)<<endl;
    }
    return 0;
}