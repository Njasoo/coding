#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 5], b[n + 5];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (n % 2 == 0) {
            double mid_val = (b[n / 2] + b[n / 2 + 1]) / 2.0;
            if (a[i] < mid_val) {
                cout << fixed << setprecision(1) << 1.0 * b[n / 2 + 1] << '\n';
            } else {
                cout << fixed << setprecision(1) << 1.0 * b[n / 2] << '\n';
            }
        } else {
            int mid_val = b[(1 + n) / 2];
            if (a[i] < mid_val) {
                cout << fixed << setprecision(1) << (b[(1 + n) / 2] + b[(1 + n) / 2 + 1]) / 2.0 << '\n';
            } else if (a[i] > mid_val) {
                cout << fixed << setprecision(1) << (b[(1 + n) / 2 - 1] + b[(1 + n) / 2]) / 2.0 << '\n';
            } else {
                cout << fixed << setprecision(1) << (b[(1 + n) / 2 - 1] + b[(1 + n) / 2 + 1]) / 2.0 << '\n';
            }
        }
    }
    return 0;
}