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
    string ans;
    cin>>ans;
    string code;
    int cnt=0,flag=0;
    while(cin>>code)
    {
        if(!flag)cnt++;
        if(code==ans)
        {
            flag=1;
        }
    }
    if(flag)cout<<"Correct\n";
    else cout<<"Wrong\n";
    cout<<cnt<<'\n';
    return 0;
}