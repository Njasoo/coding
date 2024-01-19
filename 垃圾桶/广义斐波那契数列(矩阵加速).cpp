#include<bits/stdc++.h>
using namespace std;
long long p,q,a_1,a_2,n,m;
struct Matrix{
    int l,w;
    long long f[5][5];
};
Matrix mul(Matrix A,Matrix B){
    Matrix res;
    res.l=A.l,res.w=B.w;
    for(int i=1;i<=res.l;i++){
        for(int j=1;j<=res.w;j++){
            res.f[i][j]=0;
        }
    }
    for(int i=1;i<=res.l;i++){
        for(int j=1;j<=res.w;j++){
            for(int k=1;k<=A.w;k++){
                res.f[i][j]=(res.f[i][j]+A.f[i][k]*B.f[k][j]%m)%m;
            }
        }
    }
    return res;
}
Matrix power(Matrix base,long long v){
    Matrix res;
    res.l=res.w=base.l;
    for(int i=1;i<=res.l;i++){
        for(int j=1;j<=res.w;j++){
            if(i==j)res.f[i][j]=1;
            else res.f[i][j]=0;
        }
    }
    while(v){
        if(v&1)res=mul(res,base);
        base=mul(base,base);
        v>>=1;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>p>>q>>a_1>>a_2>>n>>m;
    if(n==1){
        cout<<a_1<<'\n';
        return 0;
    }
    Matrix origin;
    origin.l=2,origin.w=1;
    origin.f[1][1]=a_2,origin.f[2][1]=a_1;
    Matrix base;
    base.l=2,base.w=2;
    base.f[1][1]=p,base.f[1][2]=q,base.f[2][1]=1,base.f[2][2]=0;
    base=power(base,n-2);
    Matrix ans=mul(base,origin);
    cout<<ans.f[1][1]<<'\n';
    return 0;
}