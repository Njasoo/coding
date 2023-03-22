#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define N 1000005
#define M 500005
#define MN 1000000
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<pair<int,string>> s(n);
    for(int i=0;i<n;i++)
    {
        cin>>s[i].second;
    }
    int pos=s[0].second.find(".");
    pos--;
    while(pos>=0 && isdigit(s[0].second[pos]))
    {
        pos--;
    }
    int len=pos+1;
    // db(len);
    for(int i=0;i<n;i++)
    {
        string temp=s[i].second.substr(len);
        stringstream ss(temp);
        char ch;
        int num;
        ss>>num>>ch>>ch>>ch;
        // db(num);
        s[i].first=num;
    }
    sort(s.begin(),s.end());
    for(int i=0;i<n;i++) cout<<s[i].second<<'\n';
    return 0;
}