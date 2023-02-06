#include <stdio.h>

int a[1000005];

int dfs(int number_of_people, int number, int round) {
    int res;
    if (round == 1) {
        res = number;
        a[res] = 0;
    } else {
        res = dfs(number_of_people + 1, number, round - 1) + number - 1;
        a[res] = 0;
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    dfs(1, m, n - 1);
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            printf("%d\n", a[i]);
            break;
        }
    }
    return 0;
}