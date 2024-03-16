#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string t1 = "xiao", t2 = "hong";
    int p = 0;
    vector<bool> mark(s.size());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t1[p]) {
            p++;
            mark[i] = true;
            if (p == t1.size()) break;
        }
    }
    p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == t2[p]) {
            if (s[i] == 'o' && mark[i]) continue;
            p++;
            mark[i] = true;
            if (p == t2.size()) break;
        }
    }
    cout << t1 << t2;
    for (int i = 0; i < s.size(); i++) {
        if (mark[i]) continue;
        cout << s[i];
    }
    cout << '\n';
    return 0;
}