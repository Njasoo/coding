#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

const int MN=1e5;
struct Node {
	ll p, c;
} t[MN+5];
ll sum[MN+5];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, S;
	cin >> n >> S;
	for (int i=1; i<=n; i++) {
		cin >> t[i].p >> t[i].c;
	}	
	sort(t+1, t+n+1, [&](Node i, Node j) {
		return i.c<j.c;
	});
	ll minus=0;
	for (int i=1; i<=n; i++) {
		sum[i]=sum[i-1]+t[i].p;
	}
	int i=1;
	ll ans=0;
	while (i<=n && S<sum[n]-sum[i-1]) {
		ans+=S*(t[i].c-minus);
		ll tmp=t[i].c;
		minus+=t[i].c-minus;
		while (i<=n && t[i].c==tmp) {
			i++;
		}
	}
//	db(minus), el;
//	db(i), el;
	for (int j=i; j<=n; j++) {
		ans+=max(0LL, (t[j].c-minus))*t[j].p;
	}
	cout << ans << "\n";
	return 0;
}

