#include<bits/stdc++.h>
using namespace std;
bool isq(int x){
    int sq=sqrt(x);
    return sq*sq==x;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>a>>b;
    bool flag=0;
    vector<int> ans;
    int real_xiebian_2=a*a+b*b;
    // cerr<<"real_xiebian="<<real_xiebian_2<<endl;
    for(int x1=-1000;x1<=0;x1++){
        int y1_2=a*a-x1*x1;
        if(y1_2<0)continue;
        if(!isq(y1_2))continue;
        int y1=sqrt(y1_2);
        for(int x2=0;x2<=1000;x2++){
            int y2_2=b*b-x2*x2;
            if(y2_2<0)continue;
            if(!isq(y2_2))continue;
            int y2=sqrt(y2_2);
            // if(!isq(xiebian_2))continue;
            //并没有要求斜边也是整数
            int xiebian_2=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
            if(x1!=0&&x1!=x2&&x2!=0&&y1!=y2&&y2!=0&&y1!=0&&xiebian_2==real_xiebian_2){
                // cerr<<"xiebian_2="<<xiebian_2<<endl;
                // cerr<<"x1="<<x1<<" "<<"y1="<<y1<<endl;
                // cerr<<"x2="<<x2<<" "<<"y2="<<y2<<endl;
                // cerr<<"xiebian_2="<<xiebian_2<<endl<<endl;
                flag=1;
                ans.push_back(x1);
                ans.push_back(y1);
                ans.push_back(x2);
                ans.push_back(y2);
                ans.push_back(0);
                ans.push_back(0);
                break;
            }
        }
        if(flag)break;
    }
    if(!flag){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<ans[0]<<" "<<ans[1]<<'\n';
    cout<<ans[2]<<" "<<ans[3]<<'\n';
    cout<<ans[4]<<" "<<ans[5]<<'\n';
    return 0;
}