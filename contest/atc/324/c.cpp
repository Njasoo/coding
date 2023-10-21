#include <bits/stdc++.h>

using namespace std;

int main() {
    map<string, bool> hs;
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    hs[s] = true;
    for (int k = 0; k < s.size(); k++) {
        string l = s.substr(0, k);
        string r = s.substr(k + 1);
        string new_string = l + r;
        hs[new_string] = true;
    }
    for (int k = 0; k < s.size(); k++) {
        for (char c = 'a'; c <= 'z'; c++) {
            string temp = s;
            s.insert(k, 1, c);
            hs[s] = true;
            s = temp;
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            string temp = s;
            s.insert(k, 1, c);
            hs[s] = true;
            s = temp;
        }
    }
    for (int i = 0; i < s.size(); i++) {
        string temp = s;
        for (char c = 'a'; c <= 'z'; c++) {
            temp[i] = c;
            hs[temp] = true;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        string new_s;
        cin >> new_s;
        if (hs[new_s]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}