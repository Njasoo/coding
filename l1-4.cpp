#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll x;
	cin >> x;
	ll now = 1;
	ll ans = 1;
	while (now <= x) {
		ans = now;
		now *= 2;
	}
	cout << ans << "\n";
	return 0;
}
