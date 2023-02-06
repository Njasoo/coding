#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct node {
	int id, time;
}a[1005];

bool cmp(node &x, node &y) {
	return x.time < y.time;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].time);
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n, cmp);
	double sum = 0;
	for (int i = 1; i <= n; i++) {
		printf("%d ", a[i].id);
	}
	printf("\n");
	for (int i = 1; i <= n; i++) {
		sum += (n - i) * a[i].time;
	}
	printf("%.2lf\n", sum / n);
	return 0;
}