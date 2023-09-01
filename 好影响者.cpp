#include <iostream>

using namespace std;

#ifndef ONLINE_JUDGE
#define debug printf
#else
#define debug(...) 114514
#endif

const int N = 2e5 + 5;
int c[N];
char s[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
    }
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    return 0;
}