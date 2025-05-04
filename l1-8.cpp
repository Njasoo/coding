#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

const int N = 1005;
bool visrow[N], viscol[N];
ll f[N][N];
vector<int> ans[N];
struct Node {
	ll v;
	int x, y;
	
	bool operator<(const Node& rhs) const {
		return !(v>rhs.v);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	priority_queue<Node> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> f[i][j];
			q.push({f[i][j], i, j});
		}
	}
	while (k--) {
		auto u = q.top();
		q.pop();
		ll v = u.v;
		int x = u.x, y = u.y;
		if (visrow[x] || viscol[y]) {
			k++;
			continue;
		}
//		db(v), el;
		visrow[x] = 1;
		viscol[y] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visrow[i] && !viscol[j]) {
				ans[i].push_back(f[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
		}
	}
	return 0;
}
