#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt[26] {};
    int mx = 0;
    for (char c : s) {
        cnt[c - 'a']++;
        mx = max(mx, cnt[c - 'a']);
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == mx) {
            cout << char(i + 'a') << '\n';
            break;
        }
    }
    return 0;
}