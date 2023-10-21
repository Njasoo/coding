#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int first;
    scanf("%d", &first);
    int flag = 1;
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        flag &= x == first;
    }
    printf(flag ? "Yes\n" : "No\n");
    return 0;
}