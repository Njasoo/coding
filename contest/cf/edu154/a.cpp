#include <iostream>
#include <cstring>

using namespace std;

#ifndef ONLINE_JUDGE
#define debug printf
#else
#define debug(...) 114514
#endif

// O(2 ^ 9 * sqrt(num))

char s[105];

void solve() {
    scanf("%s", s);
    int n = strlen(s);
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) < 2) continue;
        int num = 0;
        for (int i = 0; i < n; i++) {
            if (mask >> (n - 1 - i) & 1) {
                num = num * 10 + s[i] - '0';
            }
        }
        bool flag = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            printf("%d\n", num);
            return;
        }
    }
    printf("-1\n");
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        solve();
    }
    return 0;
}