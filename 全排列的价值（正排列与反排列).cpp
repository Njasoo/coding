#include <bits/stdc++.h>

using namespace std;
using ll=long long;
using ull=unsigned long long;

#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

/*
题意就是计算顺序数对数量的总和
一开始是的想法是计算每种顺序对数的出现次数
答案为sigma C(k,C(n,2))，但是C(n,2)太大了，想不到怎么处理
后来看了题解，考虑一个排列，它和它的反排列的价值总和为n*(n-1)/2
这样的排列对总共有n!/2对，所以答案是n!/2*n*(n-1)/2
*/
const ll MOD=998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if(n<=1){
        cout<<"0\n";
    }
    else{
        ll cnt1=1;
        ll cnt2=1LL*n*(n-1)/2%MOD;
        for(int i=3;i<=n;i++){
            cnt1*=i;
            cnt1%=MOD;
        }
        cout<<(cnt1*cnt2%MOD)<<'\n';
    }
    return 0;
}