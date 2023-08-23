#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int cnt = 0;

    for (int i = 0; i < m; i++) {
        char op;
        cin >> op;
        if (op == '+') {
            cnt++;
        } else if (op == '-') {
            cnt--;
        } else if (op == '*') {
            s.push_back('0');
        } else {
            s.pop_back();
        }
    }

    string s2;
    while (cnt) {
        s2 += cnt % 2 + '0';
        cnt /= 2;
    }

    int maxlen = max(s.size(), s2.size());
    vector<int> a(maxlen), b(maxlen);

    for (int i = 0; i < s.size(); i++) {
        a[i] = s[s.size() - 1 - i] - '0';
    }

    for (int i = 0; i < s2.size(); i++) {
        b[i] = s2[s2.size() - 1 - i] - '0';
    }

    vector<int> c(maxlen + 1);
    for (int i = 0; i < maxlen; i++) {
        c[i] += a[i] + b[i];
        if (c[i] >= 2) {
            c[i + 1] += c[i] / 2;
            c[i] %= 2;
        }
    }

    string ans = "";
    if (c[maxlen]) ans += "1";

    for (int i = maxlen - 1; i >= 0; i--) {
        ans += c[i] + '0';
    }

    cout << ans << '\n';

    return 0;
}