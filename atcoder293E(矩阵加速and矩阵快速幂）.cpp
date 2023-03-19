#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define sz(x) (int)(x).size()
long long M;
const int N=10;
struct Matrix{
    long long f[N][N];
    Matrix operator*(Matrix x){
        Matrix res;
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                res.f[i][j]=0;
            }
        }
        for(int i=1;i<=2;i++){
            for(int j=1;j<=2;j++){
                for(int k=1;k<=2;k++){
                    res.f[i][j]+=f[i][k]*x.f[k][j]%M;
                    res.f[i][j]%=M;
                }
            }
        }
        return res;
    }
};
Matrix power(Matrix F,long long k){
    Matrix res;
    for(int i=1;i<=2;i++){
        for(int j=1;j<=2;j++){
            res.f[i][j]=0;
        }
    }
    for(int i=1;i<=2;i++){
        res.f[i][i]=1;
    }
    while(k){
        if(k%2)res=res*F;
        k/=2;
        F=F*F;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long A,X;
    cin>>A>>X>>M;
    Matrix F;
    F.f[1][1]=A,F.f[1][2]=F.f[2][2]=1,F.f[2][1]=0;
    Matrix ans=power(F,X);
    long long temp[3][3];
    for(int i=1;i<=2;i++){
        for(int j=2;j<=2;j++){
            temp[i][j]=ans.f[i][j];
        }
    }
    long long temp2[3][3];
    temp2[1][1]=0,temp2[2][1]=1;
    long long real_ans[4][4]={0};
    for(int i=1;i<=2;i++){
        for(int j=1;j<=1;j++){
            for(int k=1;k<=2;k++){
                real_ans[i][j]+=temp[i][k]*temp2[k][j]%M;
                real_ans[i][j]%=M;
            }
        }
    }
    cout<<real_ans[1][1]<<'\n';
    return 0;
}