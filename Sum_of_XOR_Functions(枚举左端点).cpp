#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstdlib>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

#define ll long long
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second

const int N=3e5+5;
const int MOD=998244353;
int pref[N],pre_sum[N][30][2],len[N][30][2];

void add(int &a,ll b){
    a+=b;
    if(a>=b)a-=MOD;
    if(a<0)a+=MOD;
}

ll sum(ll a,ll b){
    a+=b;
    if(a>=MOD)a-=MOD;
    if(a<0)a+=MOD;
    return a;
}

int mul(ll a,ll b){
    return 1ll*a*b%MOD;
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pref[i]=pref[i-1]^a;
        for(int j=0;j<30;j++){
            pre_sum[i][j][0]=pre_sum[i-1][j][0];
            pre_sum[i][j][1]=pre_sum[i-1][j][1];
            len[i][j][0]=len[i-1][j][0];
            len[i][j][1]=len[i-1][j][1];
            int x=pref[i]>>j&1;
            if(x)pre_sum[i][j][1]++,add(len[i][j][1],i);
            else pre_sum[i][j][0]++,add(len[i][j][0],i);
        }
    }
    int ans=0;
    for(int j=0;j<30;j++){
        int bit=0;
        for(int i=1;i<=n;i++){
            int x=pref[i-1]>>j&1;
            int sum_of_r=sum(len[n][j][x^1],-len[i-1][j][x^1]);
            int sum_of_l_1=mul(i-1,sum(pre_sum[n][j][x^1],-pre_sum[i-1][j][x^1]));
            // (bit+=sum_of_r-sum_of_l_1)%=MOD;
            add(bit,sum(sum_of_r,-sum_of_l_1));
        }
        // (ans+=bit*(1<<j)%MOD)%=MOD;
        add(ans,mul(bit,1<<j));
    }
    cout<<ans<<endl;
    return 0;
}