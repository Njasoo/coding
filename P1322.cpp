#include <bits/stdc++.h>
using namespace std;
int solve() {
	int res = 0;
	char ch;
	while ((ch = getchar()) != EOF) {
		if (ch == ']') break;
		if (ch == '[') res += solve();
		int num;
		if (ch == 'R') {
			for (int i = 1; i <= 6; i++) getchar();
			scanf("%d", &num);
			ch = getchar();
			if (ch == '[') res += num * solve();
		}
		if (ch == 'F') {
			getchar(), getchar();
			scanf("%d", &num);
			res += num;
		}
		if (ch == 'B') {
			getchar(), getchar();
			scanf("%d", &num);
			res -= num;
		}
	}
	return res;
}
int main() {
	printf("%d\n", abs(solve()));
	return 0;
}
