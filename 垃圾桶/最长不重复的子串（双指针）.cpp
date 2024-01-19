#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

#define db(x) cerr<<(#x)<<"="<<x<<" "
#define el cerr<<endl

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin>>s;
    map<char,bool> hs;
    int i=0,ans=0,j=0;
    while(i<(int)s.size()){
        j=max(i+1,j);
        hs[s[i]]=1;
        while(j<(int)s.size()){
            if(hs[s[j]])break;
            hs[s[j]]=1;
            j++;
        }
        // if(j>i)j--;
        db(i),db(j),el;
        ans=max(ans,j-i);
        if(j==(int)s.size())break;
        hs[s[i]]=0;
        i++;
    }    
    cout<<ans<<'\n';
    return 0;
}