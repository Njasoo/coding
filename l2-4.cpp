#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

int n;
vector<ll> ans;
ll a, b;

void dfs(int p, ll cur) {
//	db(p), db(cur), el;
	if (p == n + 1) {
		if (cur >= a && cur <= b) {
			ans.push_back(cur);	
		}
		return;
	}
//	cerr << "hi\n";
//	if (p == 10) {
//		ll nex = cur * 10;
//		if (nex % p == 0) {
//			dfs(p + 1, nex);
//		}
//	} if (p == 5) {
//		for (int i = 0; i < 10; i += 5) {
//			ll nex = cur * 10 + i;
//			if (nex % p == 0) {
//	//			db(p), db(nex), el;
//				dfs(p + 1, nex);
//			}
//		}	
//	} else {
		for (int i = 0 + (p == 1); i < 10; i++) {
			ll nex = cur * 10 + i;
			if (nex % p == 0) {
	//			db(p), db(nex), el;
				dfs(p + 1, nex);
			}
		}
//	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	dfs(1, 0);
	if (ans.size() == 0) {
		cout << "No Solution\n";
	} else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
	return 0;
}
