#include <bits/stdc++.h>
using namespace std;
const int MN = 1000;
int a[MN + 5];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n, [&](int i, int j) {
        return i > j;
    });
    cout << a[k] << '\n';
    return 0;
}