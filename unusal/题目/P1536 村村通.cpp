#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

// to ling n sets, we need n - 1 lines

int f[1005];

int ancestor(int x) {
	if (x == f[x]) return x;
	return f[x] = ancestor(f[x]);
}

void join(int x, int y) {
	int f1 = ancestor(x), f2 = ancestor(y);
	f[f1] = f2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (1) {
		int ans = 0;
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		int m;
		cin >> m;
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
		for (int i = 1; i <= m; i++) {
			int x, y;
			cin >> x >> y;
			join(x, y);
		}
		for (int i = 1; i <= n; i++) {
			if (ancestor(i) == i) {
				ans++;
			}
		}
		cout << ans - 1 << '\n';
	}	
	return 0;
}