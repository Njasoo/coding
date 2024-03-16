#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 105;
char s[N], rs[N];

void solve() {
    int n;
    scanf("%d\n%s", &n, s);
    int len = strlen(s);
    strcpy(rs, s);
    reverse(rs, rs + len);
    if (strcmp(s, rs) == 1) {
        swap(s, rs);
        n--;
    }
    if (n % 2 == 0) {
        printf("%s\n", s);
    } else {
        printf("%s%s\n", s, rs);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
