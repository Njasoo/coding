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
    int n;
    cin>>n;
    string s;
    cin>>s;
    s=" "+s;
    int cntp=0,cntn=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='+')cntp++;
        else cntn++;
    }
    int q;
    cin>>q;
    while(q--){
        long long a,b;
        cin>>a>>b;
        if(a!=b){
            long long cnt1=b*(cntn-cntp);
            long long cnt2=a-b;
            if(cnt1%cnt2){
                cout<<"NO\n";
            }else{
                //0<=c<=cntp
                //0<=d<=cntn
                //-cntn<=-d<=0
                //-cntn<=c-d<=cntp
                long long lhs=b*(cntn-cntp)/(a-b);
                if(-cntn<=lhs && lhs<=cntp){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
            }
        }else{
            if(cntp==cntn){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }   
    return 0;
}