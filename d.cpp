#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ans+=a[i];
		if (a[i]%2==0) {
			ans+=a[i];
		} else {
			ans-=a[i];
		}
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ans+=a[i];
		int t=a[i];
		while (t) {
			t/=2;
			len++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		solve();
	}
	return 0;
}