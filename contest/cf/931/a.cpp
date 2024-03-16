#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
using ll=long long;

int a[105];

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	printf("%d\n",2*(a[n]+a[n-1]-a[2]-a[1]));
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}	
	return 0;
}