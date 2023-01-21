#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> ss(n);
        unordered_map<string, bool> hs;
        for (int i = 0; i < n; i++) {
            cin >> ss[i];
            hs[ss[i]] = true;
        }
        for (int i = 0; i < n; i++) {
            char ch = '0';
            for (int j = 0; j < ss[i].size(); j++) {
                string s1 = "", s2 = "";
                for (int k = 0; k < j; k++) {
                    s1 += ss[i][k];
                }
                for (int k = j; k < ss[i].size(); k++) {
                    s2 += ss[i][k];
                }
                if (hs.find(s1) != hs.end() && hs.find(s2) != hs.end()) {
                    ch = '1';
                    break;
                }
            }
            cout << ch;
        }
        cout << '\n';
    }
    return 0;
}