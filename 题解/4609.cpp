#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n % 2) {
            cout << "7";
            n -= 3;
        }
        for (int i = 0; i < n / 2; i++) cout << "1";
        cout << '\n';
    }
    return 0;
}