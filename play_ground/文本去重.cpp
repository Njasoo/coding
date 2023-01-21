#include <stdio.h>
#include <string.h>

int vis[129];

void func(char* s) {
	int n = strlen(s);
	int w = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[(int) s[i]]) {
			vis[(int) s[i]] = 1;
			s[w++] = s[i];
		}
	}
	s[w] = '\0';
}

int main() {
	char s[105];
	scanf("%s", s);
	func(s);
	printf("%s\n", s);
	return 0;
}