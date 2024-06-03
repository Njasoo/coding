#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S, T;
    cin >> S >> T;
    int last = 0;
    for (int i = 0; i < 3; i++) {
        T[i] = tolower(T[i]);
    }
    // cerr << "T = " << T << endl;
    for (int i = 0; i < 3; i++) {
        if (i == 2 && T[i] == 'x') {
            break;
        }
        bool ok = false;
        for (int j = last; j < (int)S.size(); j++) {
            if (S[j] == T[i]) {
                ok = true;
                last = j + 1;
                break;
            }
        }
        if (!ok) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}