#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
using mii=map<ll,ll>;
#define endl '\n'
#define vt vector
#define pque priority_queue
#define db(x) cerr<<#x<<"="<<(x)<<endl
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define il inline
#define cn const
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define sz(x) (int)(x).size()
#define lb lower_bound
#define up upper_bound
#define re reverse
cn int N=1e6+5;
cn int MN=1e6;
ll a[N];
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll MOD=1000000007;
void solve();
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    //cin>>tt;
    while(tt--)solve();
    return 0;
}
void solve(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i])){
            if(isupper(s1[i])){
                s1[i]=s1[i]-'A'+'a';
            }
        }
    }
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i])){
            if(isupper(s2[i])){
                s2[i]=s2[i]-'A'+'a';
            }
        }
    }
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i])){
            if(isupper(s3[i])){
                s3[i]=s3[i]-'A'+'a';
            }
        }
    }
    string check1="";
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i]))check1+=s1[i];
    }   
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i]))check1+=s2[i];
    }
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i]))check1+=s3[i];
    }
    string check2="";
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i]))check2+=s1[i];
    }   
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i]))check2+=s3[i];
    }
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i]))check2+=s2[i];
    }
    string check3="";
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i]))check3+=s2[i];
    }
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i]))check3+=s3[i];
    }
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i]))check3+=s1[i];
    }   
    string check4="";
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i]))check4+=s3[i];
    }
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i]))check4+=s2[i];
    }
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i]))check4+=s1[i];
    }   
    string check5="";
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i]))check5+=s3[i];
    }
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i]))check5+=s1[i];
    }   
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i]))check5+=s2[i];
    }
    string check6="";
    for(int i=0;i<sz(s2);i++){
        if(isalpha(s2[i]))check6+=s2[i];
    }
    for(int i=0;i<sz(s1);i++){
        if(isalpha(s1[i]))check6+=s1[i];
    }   
    for(int i=0;i<sz(s3);i++){
        if(isalpha(s3[i]))check6+=s3[i];
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string q;
        cin>>q;
        for(int i=0;i<sz(q);i++){
            if(isalpha(q[i])){
                if(isupper(q[i]))q[i]=q[i]-'A'+'a';
            }
        }
        string temp="";
        for(int i=0;i<sz(q);i++){
            if(isalpha(q[i]))temp+=q[i];
        }
        if(temp==check1||temp==check2||temp==check3||temp==check4||temp==check5||temp==check6)cout<<"ACC"<<endl;
        else cout<<"WA"<<endl;
    }
}