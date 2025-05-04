#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl

//每次纵向的移动会造成横向0.5的平移
pair<double,double> dir[6]={
    {-1,0},{-0.5,1},{0.5,1},{1,0},{0.5,-1},{-0.5,-1}
};

pair<double,double> location(int d,int p,int q){
    double nowx=0,nowy=0;
    nowx+=dir[d].first*p;
    nowy+=dir[d].second*p;
    d=(d+2)%6;
    nowx+=dir[d].first*q;
    nowy+=dir[d].second*q;
    return pair<double,double>({nowx,nowy});
}

//不能只考虑走到同一行再水平走的情况，还有一种情况是可以直接斜着走到达
//什么情况下可以直接斜着到达（在中途拐弯），那就是dy>=2*dx
ll dis(double x1,double y1,double x2,double y2){
    if(abs(y1-y2)>=2*abs(x1-x2)){
        return abs(y1-y2);
    }
    return abs(y1-y2)+abs(x1-x2)-abs(y1-y2)*0.5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d1,p1,q1,d2,p2,q2;
    cin>>d1>>p1>>q1>>d2>>p2>>q2;     
    pair<double,double> B=location(d1,p1,q1);
    pair<double,double> C=location(d2,p2,q2);
    cout<<dis(B.first,B.second,C.first,C.second)<<'\n';
    return 0;
}