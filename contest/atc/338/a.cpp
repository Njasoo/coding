#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (isupper(s[0])) {
        for (int i = 1; i < s.size(); i++) {
            if (isupper(s[i])) {
                cout << "No\n";
                return 0;
            }
        }
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}