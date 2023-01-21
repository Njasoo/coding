#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int f[5005];

int leader(int x) {
	if (x == f[x]) return x;
	return f[x] = leader(f[x]); // 状态压缩
}

void join(int x, int y) {
	int f1 = leader(x), f2 = leader(y);
	if (f1 != f2) {
		f[f1] = f2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}	
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		join(x, y);
	}
	for (int i = 1; i <= p; i++) {
		int x, y;
		cin >> x >> y;
		if (leader(x) == leader(y)) {
			cout << "Yes" << '\n';
		} else {
			cout << "No" << '\n';
		}
	}
	return 0;
}