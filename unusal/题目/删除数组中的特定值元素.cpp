#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != k) {
            a[j++] = a[i];
        }
    }
    cout << j << '\n';
    for (int i = 0; i < j; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
    return 0;
}