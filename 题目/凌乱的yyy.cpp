#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
	int l, r;
}a[1000005];

bool cmp(node &x, node &y) {
	return x.r < y.r; // 按早结束的排序
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].l, &a[i].r);
	}
	sort(a, a + n, cmp);
	int finish = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (finish <= a[i].l) {
			finish = a[i].r;
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}