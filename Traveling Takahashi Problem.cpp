#include <bits/stdc++.h>
using namespace std;
#define ll long long

double calc(ll x1,ll y1,ll x2,ll y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n;
	cin>>n;
	double ans=0;
	int nowx=0,nowy=0;
	for(int i=1;i<=n;i++){
		ll x,y;
		cin>>x>>y;
		ans+=calc(nowx,nowy,x,y);
		nowx=x,nowy=y;
	}
	ans+=calc(nowx,nowy,0,0);
	printf("%.20lf\n",ans);
	return 0;
}

