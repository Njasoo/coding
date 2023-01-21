#include <bits/stdc++.h>

using namespace std;

vector<int> p[100005];
int vis[100005];

void dfs(int x) {
	cout << x << " ";
	for (int i = 0; i < (int) p[x].size(); i++) {
		if (vis[p[x][i]] == 0) {
			vis[p[x][i]] = 1;
			dfs(p[x][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		p[x].push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		if (p[i].size() > 0) {
			sort(p[i].begin(), p[i].end());
		}
	}
	vis[1] = 1;
	dfs(1);
	cout << '\n';
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for (int i = 0; i < (int) p[u].size(); i++) {
			if (vis[p[u][i]] == 0) {
				vis[p[u][i]] = 1;
				q.push(p[u][i]);
			}
		}
	}
	cout << '\n';
	return 0;
}