#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << " "
#define el cerr << "\n"

const int MN=1e5;
struct Node {
	ll p, c;
} t[MN+5];
ll n, S;

ll calc() {
	ll res=0;
	for (int i=1; i<=n; i++) {
		if (t[i].c>0) {
			res+=t[i].p;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> S;	
	for (int i=1; i<=n; i++) {
		cin >> t[i].p >> t[i].c;
	}
	sort(t+1, t+n+1, [&](Node i, Node j) {
		return i.c<j.c;
	});
	ll ans=0;
	while (S<calc()) {
		ans+=S;
		for (int i=1; i<=n; i++) {
			if (t[i].c>0) {
				t[i].c--;
			}
		}
	}
	for (int i=1; i<=n; i++) {
		if (t[i].c) {
			ans+=t[i].p*t[i].c;
		}
	}
	cout << ans << "\n";
	return 0;
}

