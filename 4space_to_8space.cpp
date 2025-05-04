#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (getline(cin, s)) {
        int cnt_space = 0;
        int p = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ' ') {
                cnt_space++;
            } else {
                p = i;
                break;
            }
        }
        for (int i = 0; i < 2 * cnt_space; i++) {
            cout << " ";
        }
        for (int i = p; i < (int)s.size(); i++) {
            cout << s[i];
        }
        cout << "\n";
    }
    return 0;
}