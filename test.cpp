#include <bits/stdc++.h>

using namespace std;

int n, a[100001], k;

int read() {
    int s = 0, w = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') {
            w = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}


void qsort(int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left, j = right;
    while (i < j) {
        while (j > i && a[j] >= a[left]) {
            j--;
        }
        while (i < j && a[i] <= a[left]) {
            i++;
        }
        if (i == j) {
            swap(a[i], a[left]);
        } else {
            swap(a[i], a[j]);
        }
    }
    qsort(left, i - 1);
    qsort(j + 1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    qsort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}