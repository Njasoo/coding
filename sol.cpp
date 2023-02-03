/**
  *    author:  Njaso
  *    created: 22.06.2022 20:45:11
**/
#include <bits/stdc++.h>

using namespace std;

void solve(string str) {
    int cnt = 0;
    for (int i = 0; i < (int) str.size(); i++) {
        if (str[i] == ' ') {
            cnt++;
        } else {
            break;             
        }
    }
    for (int i = 0; i < cnt; i++) {
        cout << " ";
    }
    cout << str << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in1", "r", stdin);
    freopen("out", "w", stdout);
    string str;
    while (getline(cin, str)) {
        solve(str);
    }
    return 0;
}
