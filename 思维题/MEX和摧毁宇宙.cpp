#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
    int n;
    cin >> n;
    int full_of_zeros = 1, first_not0_pos = 0, last_not0_pos = 0;
    int zero_in_the_middle = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i]) {
            full_of_zeros = 0;
        }
        if (first_not0_pos == 0 && a[i]) {
            first_not0_pos = i;
        }
        if (first_not0_pos != 0 && a[i]) {
            last_not0_pos = i;
        }
    }
    if (full_of_zeros) {
        cout << 0 << '\n';
        return;
    }
    for (int i = first_not0_pos; i <= last_not0_pos; i++) {
        if (a[i] == 0) {
            zero_in_the_middle = 1;
        }
    }
    if (zero_in_the_middle) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }      
    return 0;
}