#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

int n;

ll get(string str) {
	ll h = 0;
	ll m = 0;
	ll s = 0;
	for (int i = 0; i < 2; i++) {
		h = h * 10 + str[i] - '0';
	}
	for (int i = 3; i < 5; i++) {
		m = m * 10 + str[i] - '0';
	}
	for (int i = 6; i < 8; i++) {
		s = s * 10 + str[i] - '0';
	}
	m *= 60;
	h *= 60 * 60;
	return h + m + s;
}

struct Node {
	ll a, b;
} t[100005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string sa, sb;
		cin >> sa >> sb;
		t[i].a = get(sa);
		t[i].b = get(sb);
	}
	sort(t + 1, t + n + 1, [&](Node i, Node j) {
		return i.a < j.a;
	});
//	for (int i = 1; i <= n; i++) {
//		cout << t[i].a << " " << t[i].b << "\n";
//	}
	int ans = 0;
	priority_queue<ll, vector<ll>, greater<ll>> q;
	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			ans++;
		} else {
			if (q.top() <= t[i].a) {
				q.pop();
			} else {
				ans++;
			}
		}
		q.push(t[i].b);
	}
	cout << ans << "\n";
	return 0;
}
