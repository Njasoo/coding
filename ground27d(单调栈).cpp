#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define sz(x) (int)(x).size()
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;

//a[i]=2^pi*x, a[j]=2^p[j]*y
//2^p[i]*x+2^p[j]*y<=x+2^(p[i]+p[j])*y是转移条件
//=>x<=2^p[j]*y
//为什么这题会想到用栈呢,它满足了一个什么性质,注意到对于每个i都要贡献给j>i,如果结果相同,那么选择更大的j是最有的
//反过来就是对于j选择之前最接近自己的i是最好的,像是单调栈的思想
//比较模糊的来讲,如果贡献相同,那么都更倾向于向后传递
//具有传递性
//重点是这道题是数学题

const int N=2e5+5;
const ll MOD=1e9+7;
ll a[N],b[N];
int cnt[N];

ll power(ll u,ll v){
    ll res=1;
    while(v){
        if(v%2)res=res*u%MOD;
        u=u*u%MOD;
        v/=2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin>>tt;
    while(tt--){
        int n;
        cin>>n;
        for(int i=1; i<=n; i++){
            cnt[i]=0;
        }
        for(int i=1; i<=n; i++){
            cin>>a[i];
            b[i]=a[i];
            while(b[i]%2==0){
                b[i]/=2;
                cnt[i]++;
            }
        }
        vector<int> stk;
        ll ans=0;
        for(int i=1; i<=n; i++){
            ans+=a[i];
            ans%=MOD;
            while(!stk.empty() && b[stk.back()]<=a[i]){ //b[stk.back()]<=a[i]是因为如果前面某个位置j更值得pre去贡献,那么它必然已经贡献了
                //我在纠结的是,是否存在一个位置j使得它不值得pre去贡献,但是它值得去贡献给i,然后存在一个j2>j也值得pre去贡献,这是不可能的,因为这样的话,他就会贡献给j2
                int pre=stk.back();
                //b[pre]*2^cnt[pre]=b[pre]
                ans=(((ans-b[pre]*power(2,cnt[pre]))%MOD)+MOD)%MOD;
                ans+=b[pre];
                ans%=MOD;
                ans=(ans+power(2,cnt[i]+cnt[pre])*b[i]%MOD)%MOD;
                ans=(((ans-a[i])%MOD)+MOD)%MOD;
                cnt[i]+=cnt[pre];
                cnt[pre]=0;
                stk.pop_back();
            }
            stk.push_back(i); //如果pre不传给i,而i+1对于pre是值得贡献的,i也会对i+1进行贡献
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}