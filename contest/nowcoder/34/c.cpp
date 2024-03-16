#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    string t;
    vector<string> ans;
    for (int i = 0; i < s.size(); i++) {
        t += s[i];
        for (char c : {'0', '2', '4', '6', '8'}) {
            if (c == s[i]) {
                ans.push_back(t);
                t = "";
                break;
            }
        }
    }   
    sort(ans.begin(), ans.end(), [&](auto i, auto j) {
        if (i.size() == j.size()) {
            return i < j;
        }
        return i.size() < j.size();
    });
    for (auto x : ans) {
        cout << x << "\n";
    }
    return 0;
}