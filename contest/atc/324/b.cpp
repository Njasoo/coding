#include <bits/stdc++.h>

using namespace std;

int main() {
    int64_t N;
    scanf("%lld", &N);
    while (N % 2 == 0) {
        N /= 2;
    }
    while (N % 3 == 0) {
        N /= 3;
    }
    if (N != 1) printf("No\n");
    else printf("Yes\n");
    return 0;
}