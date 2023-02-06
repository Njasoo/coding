#include <bits/stdc++.h>

using namespace std;

int n, a[100001];

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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    qsort(1, n);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}