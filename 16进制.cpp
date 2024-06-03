#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
#define db(x) cerr<<(#x)<<"="<<(x)<<" "
#define el cerr<<endl
#define endl '\n'

map<int,char> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<10;i++){
        mp[i]=i+'0';
    }
    for(int i=10;i<16;i++){
        mp[i]='a'+i-10;
    }
    int n;
    cin>>n;
    string ans;
    while(n){
        ans.push_back(mp[n%16]);
        n/=16;
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}