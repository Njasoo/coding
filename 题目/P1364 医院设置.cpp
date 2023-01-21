#include <bits/stdc++.h>

using namespace std;

bool vis[105];

struct node {
	int value, father, left, right;
}t[105];

int cal(int x, int d) {
	if (x == 0 || vis[x]) return 0;
	vis[x] = 1;
	return t[x].value * d + cal(t[x].left, d + 1) + cal(t[x].right, d + 1) + cal(t[x].father, d + 1);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &t[i].value, &t[i].left, &t[i].right);
	}
	for (int i = 1; i <= n; i++) {
		t[t[i].left].father = i;
		t[t[i].right].father = i;
	}	
	int ans = 0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		ans = min(ans, cal(i, 0));
	}
	printf("%d\n", ans);
	return 0;
}