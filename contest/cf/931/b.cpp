#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
using namespace std;
using ll=long long;

int temp[]={1,3,6,10,15};

int rec(int num){
	if(num==0){
		return 0;
	}
	int res=1e9;
	for(int i=0;i<5;i++){
		if(temp[i]<=num){
			res=min(res,rec(num-temp[i]));
		}
	}
	return res+1;
}

void solve(){
	int n;
	scanf("%d",&n);
	printf("%d\n",rec(n));
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}	
	return 0;
}