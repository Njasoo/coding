#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstring>

using namespace std;

const int N = 100005;
int n;

struct node {
	int l, r;
}t[N];

int dfs(int x) {
	if (x == 0) return 0;
	return max(dfs(t[x].l), dfs(t[x].r)) + 1;
}

int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i].l >> t[i].r;
	}
	cout << dfs(1) << '\n';
	return 0;
}