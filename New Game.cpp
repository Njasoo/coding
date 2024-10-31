#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e5+5;
int a[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin>>tt;
	while(tt--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		map<int,int> cnt;
		sort(a+1,a+1+n);
		int l=1,r=1;
		int dis=0,ans=0;
		while(l<=n){
			if(l==r){
				cnt[a[l]]++;
				if(cnt[a[l]]==1)dis++;
			}
			while(r+1<=n && a[r+1]-a[r]<=1 && dis<=k){
				r++;
				cnt[a[r]]++;
				if(cnt[a[r]]==1)dis++;
			}
			if(dis>k){
				cnt[a[r]]--;
				dis--;
				r--;
			}
			ans=max(ans,r-l+1);
			l++;
		}
		cout<<ans<<'\n';
	}	
	return 0;
}

