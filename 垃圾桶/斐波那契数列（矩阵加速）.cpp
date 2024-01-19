#include<bits/stdc++.h>
using namespace std;
struct Matrix{
    int n,m;
    long long f[4][4];
};
Matrix mul(Matrix A,Matrix B){
    Matrix res;
    res.n=A.n;
    res.m=B.m;
    for(int i=0;i<A.n;i++){
        for(int j=0;j<B.m;j++){
            res.f[i][j]=0;
        }
    }
    for(int i=0;i<A.n;i++){
        for(int j=0;j<B.m;j++){
            for(int k=0;k<A.m;k++){
                res.f[i][j]=(res.f[i][j]+A.f[i][k]*B.f[k][j]%1000000007)%1000000007;
            }
        }
    }
    return res;
}
Matrix power(Matrix A,long long v){
    Matrix res;
    res.n=A.n;
    res.m=A.m;
    for(int i=0;i<res.n;i++){
        for(int j=0;j<res.m;j++){
            if(i==j)res.f[i][j]=1;
            else res.f[i][j]=0;
        }
    }
    while(v){
        if(v&1)res=mul(res,A);
        A=mul(A,A);
        v>>=1;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    if(n==1){
        cout<<"1\n";
        return 0;
    }
    Matrix base;
    base.n=2;
    base.m=2;
    base.f[0][0]=1,base.f[0][1]=1,base.f[1][0]=1,base.f[1][1]=0;
    base=power(base,n-2);
    Matrix origin;
    origin.n=2;
    origin.m=1;
    origin.f[0][0]=origin.f[1][0]=1;
    Matrix ans=mul(base,origin);
    cout<<ans.f[0][0]<<'\n';
    return 0;
}