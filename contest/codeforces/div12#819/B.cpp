#include <bits/stdc++.h>

using namespace std;

const int N = 1055;
int f[N][N];

void dfs(int len, int x, int y) {
	for (int i = x; i <= x + len / 2; i++) {
		for (int j = y; j <= y + len / 2; j++) {
			f[i][j] = 0;
		}
	}
	dfs(len / 2, x + len / 2, y);
	dfs(len / 2, x, y + len / 2);
	dfs(len / 2, x + len / 2, y + len / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 	int n;
 	cin >> n;
 	for (int i = 1; i <= (1 << n); i++) {
 		for (int j = 1; j <= (1 << n); j++) {
 			f[i][j] = 1;
 		}
 	}
 	dfs(1 << n, 1, 1);
 	for (int i = 1; i <= (1 << n); i++) {
 		for (int j = 1; j <= (1 << n); j++) {
 			cout << f[i][j] << " \n"[j == (1 << n)];
 		}
 	}
    return 0;
}