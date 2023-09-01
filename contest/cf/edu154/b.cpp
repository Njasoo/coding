#include <iostream>
#include <cstring>

using namespace std;

#ifndef ONLINE_JUDGE
#define debug printf
#else
#define debug(...) 114514
#endif

char a[5005], b[5005];

void solve() {
    scanf("%s\n%s", a + 1, b + 1);
    int n = strlen(a + 1);
    for (int i = 1; i < n; i++) {
        if (a[i] == '0' && a[i + 1] == '1' && a[i] == b[i] && a[i + 1] == b[i + 1]) {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        solve();
    }
    return 0;
}