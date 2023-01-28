#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<x<<endl;
//a+b=a^b+2(a&b)->x=2(a&b),so x%2=0
//set a&b=y,so a+b=x+2y->y=x/2,显然a=x,b=2y是不行的，因为这样a^b=0
//a=x+y=3x/2,b=y;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int x;
        cin>>x;
        if(x%2){
            cout<<"-1\n";
            continue;
        }
        if(((3*x/2)^(x/2))==x){
            cout<<3*x/2<<' '<<x/2<<'\n';
        }else{
            cout<<"-1\n";
        }
    }
    return 0;
}