#include <stdio.h>
#include <string.h>

char s[1005];

int isc(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}

int main() {
    gets(s);
    strcat(s, " ");
    int len = strlen(s);
    int flag = 0;
    int ans = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ') {
            if (flag) {
                ans++;
            }
            continue;
        }
        if (!isc(s[i]))
            flag = 0;
        else
            flag = 1;
    }
    printf("%d\n", ans);
    return 0;
}