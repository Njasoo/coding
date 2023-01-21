#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n < 2) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
        return 0;
    }
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (a[j] != a[i]) {
            a[++j] = a[i];
        }
    }
    cout << ++j << '\n';
    for (int i = 0; i < j; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}