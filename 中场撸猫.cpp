#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

const int N=1005;
ll b[N][N];
ll n;
multiset<ll> ms[N];
ll a[N][N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			ms[i].clear();
		}
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				cin >> b[i][j];
				ms[i].insert(b[i][j]);
			}
	//		sort(b[i]+1, b[i]+i+1);
		}	
		ll ans=0;
		for (int i=1; i<=n; i++) {
			bool flag=1;
			if (i==1) {
				a[i][i]=*ms[i].begin();
				ms[i].erase(ms[i].begin());
				ans++;
				continue;
			}
			for (int j=1; j<=i; j++) {
				if (j==1) {
					auto it=ms[i].lower_bound(a[i-1][j]);
					if (it==ms[i].end()) {
						flag=0;
						break;
					}
					else {
						a[i][j]=*it;
						ms[i].erase(it);
					}
				}
				else if (j==i) {
					auto it=ms[i].lower_bound(a[i-1][j-1]);
					if (it==ms[i].end()) {
						flag=0;
						break;
					}
					else {
						a[i][j]=*it;
						ms[i].erase(it);
					}
				}
				else {
					//a[i-1][j-1] and a[i-1][j]
					ll mx=max(a[i-1][j-1], a[i-1][j]);
					auto it=ms[i].lower_bound(mx);
					if (it==ms[i].end()) {
						flag=0;
						break;	
					}
					else {
						a[i][j]=*it;
						ms[i].erase(it);
					}
				}
			}
			if (!flag) {
				break;
			} else {
				ans++;
			}
		}
		cout << ans << "\n";	
	}
	return 0;
}

