#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

const int N = 505;
ll b, n, m, K;
ll dp1[N][N], dp2[N][N], dp22[N][N];
ll dis1[N], dis2[N];
bool finded;
bool vis[N];
struct Node {
	int to;
	ll t1, t2;
};
struct Node2 {
	int to;
};
vector<Node> adj[N];

void dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		dis1[i] = -1e18;
		dis2[i] = 1e18;
		vis[i] = 0;
	}
	dis1[s] = 0;
	dis2[s] = 0;
	priority_queue<pair<ll, ll>> q;
	q.push({dis1[s], s});
	while (!q.empty()) {
		auto tp = q.top();
		ll d = tp.first;
		ll u = tp.second;
		q.pop();
//		db(u), el;
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		for (auto x : adj[u]) {
			int v = x.to;
			ll t1 = x.t1;
			ll t2 = x.t2;
			if (d + t2 > dis1[v]) {
				dis1[v] = d + t2;
				dis2[v] = min(dis2[v], dis2[u] + t1);
				q.push({dis1[v], v});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		dp2[s][i] = dis1[i];
		dp22[s][i] = dis2[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> b >> n >> m >> K;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp2[i][j] = -1e18;
			dp1[i][j] = 1e18;
			dp22[i][j] = 1e18;
		}
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		ll t1, t2;
		cin >> t1 >> t2;
		adj[u].push_back({v, t1, t2});
		adj[v].push_back({u, t1, t2});
		dp1[u][v] = min(dp1[u][v], t1);
		dp1[v][u] = min(dp1[v][u], t1);
		dp2[u][v] = max(dp2[u][v], t2);
		dp2[v][u] = max(dp2[v][u], t2);
	}
//	cerr << "hi\n";
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp1[i][j] = min(dp1[i][j], dp1[i][k] + dp1[k][j]);
			}
		}
	}
	for (int _ = 1; _ <= K; _++) {
		int s;
		cin >> s;
		vector<int> ans1, ans2;
		for (int j = 1; j <= n; j++) {
			if (j == s) {
				continue;
			}
			if (dp1[s][j] <= b) {
				ans1.push_back(j);
			}
		}
		for (int j = 1; j <= n; j++) {
			if (j == s) {
				continue;
			}
//			finded = 0;
//			for (int i = 1; i <= n; i++) {
//				vis[i] = 0;
//			}
//			vis[s] = 1;
//			dfs(s, j, dp2[s][j], 0, 0);
//			if (finded) {
//				ans2.push_back(j);
//			}
//			db(dp22[s][j]), el;
			if (dp22[s][j] <= b) {
				ans2.push_back(j);
			}
		}
		if (ans1.size() == 0) {
			
		} else {
			for (int i = 0; i < ans1.size(); i++) {
				cout << ans1[i] << " \n"[i == ans1.size() - 1];
			}
		}
		if (ans2.size() == 0) {
		} else {
			for (int i = 0; i < ans2.size(); i++) {
				cout << ans2[i] << " \n"[i == ans2.size() - 1];
			}
		}
		if (ans1.size() == 0 && ans2.size() == 0) {
			cout << "T_T\n";
		}
	}
	return 0;
}
