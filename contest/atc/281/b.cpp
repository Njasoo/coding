#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    bool f1 = 0, f2 = 1;
    if (s[0] >= 'A' && s[0] <= 'Z' && s.back() >= 'A' && s.back() <= 'Z') f1 = 1;
    for (int i = 1; i < s.size() - 1; i++) {
        if (!isdigit(s[i])) f2 = 0;
    }
    if (f1 && f2) {
        if (s.size() - 2 != 6) {
            cout << "No\n";
        } else {
            long long cnt = 0;
            for (int i = 1; i < s.size() - 1; i++) {
                cnt = cnt * 10 + s[i] - '0';
            }
            if (cnt >= 100000 && cnt <= 999999) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    } else {
        cout << "No\n";
    }
    return 0;
}