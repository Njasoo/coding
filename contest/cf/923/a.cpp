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
        int pos1 = -1, pos2 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B') {
                pos1 = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'B') {
                pos2 = i;
                break;
            }
        }
        cout << pos2 - pos1 + 1 << '\n';
    }
    return 0;
}