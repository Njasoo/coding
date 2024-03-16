#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    string s = to_string(x);
    int cnt0 = count(s.begin(), s.end(), '0');
    sort(s.begin(), s.end());
    cout << s[cnt0];
    for (int i = 0; i < cnt0; i++) {
        cout << 0;
    }
    for (int i = cnt0 + 1; i < s.size(); i++) {
        cout << s[i];
    }
    cout << '\n';
    return 0;
}