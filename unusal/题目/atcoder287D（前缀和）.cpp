#include<bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<x<<endl;
const int N=3e5+5;
//这么简单我昨天居然没有想到
//如果两个字符串都是match的，那么前x个都要match，后sz（t）-x个也都要match
//那么搞一个前缀和后缀数组判断是否match就行
bool pre[N],suf[N];
bool match(char a,char b){
    return (a=='?'||b=='?'||a==b);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s,t;
    cin>>s>>t;       
    int lent=t.size();
    pre[0]=1;
    s=' '+s,t=' '+t;
    for(int i=1;i<=lent;i++){
        if(match(s[i],t[i]))pre[i]=1;
        else break;
    }
    reverse(s.begin()+1,s.end());
    reverse(t.begin()+1,t.end());
    suf[0]=1;
    for(int i=1;i<=lent;i++){
        if(match(s[i],t[i]))suf[i]=1;
        else break;
    }
    for(int i=0;i<=lent;i++){
        if(pre[i]&&suf[lent-i])cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}