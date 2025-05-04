#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

const int MN=2e5;
ll c[MN+5], d[MN+5];
vector<int> adj1[MN+5], adj2[MN+5];
ll n, m;
int ans=0;

void dfs(int u, int pu, int v, int pv, int cur) {
	ans=max(ans, cur);
	for (int v1 : adj1[u]) {
		if (v1==pu) continue;
		for (int v2 : adj2[v]) {
			if (v2==pv) continue;
			if (c[v1]==d[v2]) {
				dfs(v1, u, v2, v, cur+1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
	}	
	for (int i=1; i<=m; i++) {
		cin >> d[i];
	}
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	for (int i=1; i<m; i++) {
		int u, v;
		cin >> u >> v;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	if (c[1]!=d[1]) {
		cout << "0\n";
	} else {
		dfs(1, 0, 1, 0, 1);
		cout << ans << "\n";
	}
	return 0;
}

