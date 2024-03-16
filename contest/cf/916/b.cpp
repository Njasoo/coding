#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= k + 1; i++) {
            cout << n - k - 1 + i << " ";
        }
        for (int i = n - k - 1; i >= 1; i--) {
            cout << i << " ";
        }
        cout << '\n';
    }   
    return 0;
}