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
        string s;
        cin >> s;
        int min_change_step = 0;
        int tot_pair = n / 2;
        for (int l = 0, r = n - 1; l < r; l++, r--) {
            if (s[l] != s[r]) {
                min_change_step++;
                tot_pair--;
            }
        }
        if (min_change_step == 0) {
            cout << "1";
        } else {
            cout << "0";
        }
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i < min_change_step) {
                    cout << "0";
                } else {
                    if (i % 2 == 0) {
                        cout << "0";
                    } else {
                        cout << "1";
                    }
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (i < min_change_step) {
                    cout << "0";
                } else {
                    if (i / 2 > tot_pair) {
                        cout << "0";
                    } else {
                        cout << "1";
                    }
                }
            }
        }
        cout << '\n';
    }      
    return 0;
}