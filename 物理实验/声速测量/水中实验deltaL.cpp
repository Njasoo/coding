#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 6;
    vector<double> l(n);
    double sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        sum += l[i];
    }
    double l_bar = sum / n;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (l[i] - l_bar) * (l[i] - l_bar);
    }
    cerr << "sum = " << sum << endl;
    double ans = sum / n / (n - 1);
    cout << ans << '\n';
    return 0;
}