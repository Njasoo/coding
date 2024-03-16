#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<string> ans;
    for (int i = 1; i < s.size(); i++) {
        string tmp = "";
        tmp += s[i - 1];
        tmp += s[i];
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) {
        cout << x << '\n';
    }
    return 0;
}