#include <stdio.h>
#include <string.h>
int string_to_int(char *s) {
    int len = strlen(s);
    int res = 0;
    for (int i = 0; i < len; i++) {
        res = res * 10 + s[i] - '0';
    }
    return res;
}
int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        char s[32];
        scanf("%s", s);
        int len = strlen(s);
        char rs[32];
        for (int i = len - 1; i >= 0; i--) {
            rs[len - 1 - i] = s[i];
        }
        rs[len] = '\0';
        if (s[len - 1] == '0') {
            printf("%s %s\n", s, rs);
            continue;
        }
        int n = string_to_int(s);
        int m = string_to_int(rs);
        if (m % n == 0) {
            printf("%d*%d=%d\n", n, m / n, m);
        } else {
            printf("%s %s\n", s, rs);
        }
    }
    return 0;
}