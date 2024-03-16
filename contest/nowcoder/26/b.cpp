#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    string s;
    cin >> s;
    string t1 = s;
    for (int i = 1; i < t1.size(); i++) {
        if (t1[i - 1] == '0') {
            t1[i] = (t1[i] == '0' ? '1' : '0');
            t1[i - 1] = '1';
        }
    }
    if (set<char>(t1.begin(), t1.end()).size() == 1) {
        cout << "Yes\n";
        return;
    }
    string t2 = s;
    for (int i = 0; i < t2.size(); i++) {
        if (t2[i - 1] == '1') {
            t2[i] = (t2[i] == '0' ? '1' : '0');
            t2[i - 1] = '0';
        }
    }
    if (set<char>(t2.begin(), t2.end()).size() == 1) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }   
    return 0;
}