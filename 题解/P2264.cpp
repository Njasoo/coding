#include <bits/stdc++.h>

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> s(n);
    map<string, bool> in, vis;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (char &c : s[i]) {
            if (isalpha(c) && isupper(c)) {
                c = tolower(c);
            }
        }
        in[s[i]] = true;
    }   

    // cerr << "in.size() = " << in.size() << endl;

    vector<string> strs;
    string cur = "";

    char ch;
    while ((ch = getchar()) != EOF) {
        if (ch == '.') {
            strs.push_back(cur);
            cur = "";
            continue;
        }
        cur += ch;
        if (!isalpha(ch)) cur += " ";
    }


    int ans = 0;

    // cerr << strs.size() << endl;

    for (auto str : strs) {
        // cerr << "str = " << str << endl;
        stringstream ss(str);
        string tmp;
        while (ss >> tmp) {
            for (char &c : tmp) {
                if (isalpha(c) && isupper(c)) {
                    c = tolower(c);
                }
            }
            while (tmp.size() > 0 && !isalpha(tmp.back())) {
                tmp.pop_back();
            }
            if (in[tmp] && !vis[tmp]) {
                ans++;
                vis[tmp] = true;
            }
        }
        vis.clear();
    }
    // assert(false);

    cout << ans << '\n';

    return 0;
}