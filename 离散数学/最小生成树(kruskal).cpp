#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int f[N];
struct Edge {
    int from, to, cost;
}e[N];

int find(int x) {
    while (x != f[x]) {
        x = f[x] = f[f[x]];
    }
    return x;
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    f[y] = x;
    return 1;
}

bool cmp(Edge i, Edge j) {
    return i.cost < j.cost;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &e[i].from, &e[i].to, &e[i].cost);
    }
    sort(e + 1, e + 1 + m, cmp);
    for (int i = 1; i <= m; i++) {
        printf("%d ", e[i].cost);
    }
    puts("");
    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        if (!merge(e[i].from, e[i].to)) {
            printf("skip: %c %c\n", char(e[i].from + 'a' - 1), char(e[i].to + 'a' - 1));
            continue;
        }
        printf("add: %c %c cost: %d\n", char(e[i].from + 'a' - 1), char(e[i].to + 'a' - 1), e[i].cost);
        ans += e[i].cost;
    }
    printf("total cost: %lld", ans);
    return 0;
}