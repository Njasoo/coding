#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << "\n"

pair<int, int> inv[1000005];
ll sum[1000005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> id(n + 1, vector<int>(m + 1));
	vector<vector<ll>> s(n + 1, vector<ll>(m + 1));
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
			id[i][j] = ++cnt;
			inv[cnt] = {i, j};
//			db(inv[cnt].first), el;
		}
	}
	vector<vector<ll>> dist(cnt + 1, vector<ll>(cnt + 1));
	for (int i = 1; i <= cnt; i++) {
		for (int j = 1; j <= cnt; j++) {
			int x1 = inv[i].first;
			int y1 = inv[i].second;
			int x2 = inv[j].first;
			int y2 = inv[j].second;
			dist[i][j] = dist[j][i] = max(abs(x1 - x2), abs(y1 - y2));
//			db(dist[i][j]), el;
			sum[i] += dist[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << s[i][j] * sum[id[i][j]] << " \n"[j == m];
		}
	}
	return 0;
}
