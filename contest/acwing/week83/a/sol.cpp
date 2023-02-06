#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    vector<bool> vis(26);
    int cnt = 0;
    for (char c : s) {
        if (!vis[c - 'a']) {
            vis[c - 'a'] = 1;
            cnt++;
        }
    }   
    cout << (cnt % 2 ? "odd" : "even") << '\n';
    return 0;
}