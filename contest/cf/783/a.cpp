#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
#define endl '\n'
const int MOD=998244353;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n,m;
        cin>>n>>m;
        if(n==1 && m==1){
            cout<<0<<endl;
            continue;
        }
        if(min(n,m)==1){
            if(max(n,m)==2){
                cout<<1<<endl;
            }else{
                cout<<"-1\n";
            }
            continue;
        }
        
    }
    return 0;
}