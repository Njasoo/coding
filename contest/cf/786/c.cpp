#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int MOD=998244353;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        if(t.find("a")!=string::npos){
            if(t.size()==1){
                cout<<1<<'\n';
            }else{
                cout<<-1<<'\n';
            }
        }else{
            cout<<(1LL<<s.size())<<'\n';
        }
    }   
    return 0;
}