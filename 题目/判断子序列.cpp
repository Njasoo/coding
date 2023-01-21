#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int k = 0;
    for (int i = 0; i < (int)t.size(); i++) {
        if (t[i] == s[k]) {
            k++;
        }
    }
    cout << (k == (int)t.size() ? "YES" : "NO") << '\n';
    return 0;
}