#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
#define endl '\n'
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int now,pre=0,ans=0;
    bool down=0;
    for(int i=1;i<=n;i++){
        cin>>now;
        if(now<pre){
            down=1;
        }
        if(now>pre && down){
            ans++;
            down=0;
        }
        pre=now;
    }
    cout<<ans<<endl;
    return 0;
}