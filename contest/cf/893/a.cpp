#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    long long suma = a + c / 2 + (c % 2), sumb = b + c / 2;
    if (suma > sumb) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}