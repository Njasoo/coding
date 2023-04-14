#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> cntt;
        for (int i = 0; i < t.size(); i++) {
            cntt[t[i]]++;
        }
        int need = t.size();
        int l = -1, r = -1;
        int mn = (int)1e9;
        for (int i = 0, j = 0; i < s.size(); i++) {
            while (j < s.size() && need) {
                if (cntt.find(s[j]) != cntt.end()) {
                    cntt[s[j]]--;
                    if (cntt[s[j]] >= 0) {
                        need--;
                    }
                }
                j++;
            }
            if (need) break;
            if (j - i < mn) {
                mn = j - i;
                l = i;
                r = j - 1;
            }
            if (cntt.find(s[i]) != cntt.end()) {
                cntt[s[i]]++;
                if (cntt[s[i]] >= 0) {
                    need++;
                }
            }
        }
        cerr << "l = " << l << " " << "r = " << r << endl;
        if (l == -1) return string{};
        return s.substr(l, r - l + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s, t;
    cin >> s >> t;
    Solution sol;
    cout << sol.minWindow(s, t) << '\n';
    return 0;
}