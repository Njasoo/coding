#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    char ch;
    cin >> n >> ch;
    string s;
    cin >> s;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ch) ans += min(i + 1, n - i);
    }
    cout << ans << '\n';
    return 0;
}