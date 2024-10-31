#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr<<#x<<"="<<(x)<<" "
#define el cerr<<endl
#define ll long long

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n=2021041820210418LL;
	ll ans=0;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			ll L,part2;
			if(i>n/i){
				L=n/i;
				part2=i;
			}
			else{
				L=i;
				part2=n/i;
			}
			for(ll j=1;j*j<=part2;j++){
				if(part2%j==0){
					ll W,H;
					if(j<part2/j){
						W=j;
						H=part2/j;
					}
					else{
						W=part2/j;
						H=j;
					}
					if(L<=W && W<=H){
						int cnt=1;
						if(L!=W) cnt++;
						if(W!=H) cnt++;
						if(cnt==3){
							ans+=6;
						}
						else if(cnt==2){
							ans+=3;
						}
						else{
							ans++;
						}
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

