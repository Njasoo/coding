#include <bits/stdc++.h>

using namespace std;

// 如果存在a[i] == k, a[j] == k + 1, 那么除非选了x == k + 1, 不然这两个数字永远不会归位(j < i)
// 只要不存在a[i] == k, a[j] == k + 1, j < i, 这个数列就排好序了

const int N = 1e5 + 5;
int pos[N];

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) {
            ans++;
        }
    }
    printf("%d\n", ans);
}

int main() {
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        solve();
    }
    return 0;
}