#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << endl

ll n, l, r;

bool check(ll mid, ll v) {
	return mid*(mid-1)/2<v;
}

pair<ll, ll> get(ll v) {
	ll lo=1, hi=n;
	pair<ll, ll> res;
	ll bans=-1;
	while (lo<=hi) {
		ll mid=(lo+hi)/2;
		if (check(mid, v)) {
			lo=mid+1;
			bans=mid;
		} else {
			hi=mid-1;
		}
	}
	res.first=bans;
	res.second=v-(bans*(bans-1)/2);
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> l >> r;
		pair<ll, ll> res1=get(l), res2=get(r);
//		db(res1), db(res2), el;
		if (res1.first==res2.first) {
			cout << "Yes\n";
		} else {
			if (res2.first==res1.first+1 && res2.second<res1.second) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	return 0;
}

