#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int n;
    cin >> n;
    char k;
    cin >> k;
    vector<string> s(n + n);
    // auto comp = [&](string a, string b) -> int {
    //     if (a.back() == b.back()) {
    //         if (a[0] > b[0]) return 1;
    //         return -1;
    //     }
    //     if (a.back() == k) return 1;
    //     if (b.back() == k) return -1;
    //     return 0;
    // };
    map<char, vector<string>> g;
    for (int i = 0; i < n + n; i++) {
        cin >> s[i];
        g[s[i].back()].push_back(s[i]);
    }
    // 某种牌有x张，这种牌可以分成x/2组
    int cnt = 0;
    int king_size = g[k].size();
    vector<char> temp;
    for (auto [x, y] : g) {
        if (x == k) continue;
        if (y.size() % 2 && king_size) {
            cnt++, king_size--;
            temp.push_back(x);
        }
        cnt += y.size() / 2;
    }
    cnt += king_size / 2;
    if (cnt < n) {
        cout << "IMPOSSIBLE\n";
    } else {
        while (!temp.empty()) {
            char ch = temp.back();
            temp.pop_back();
            string temp2 = g[ch].back();
            g[ch].pop_back();
            cout << temp2 << " " << g[k].back() << '\n';
            g[k].pop_back();
        }
        for (auto [x, y] : g) {
            sort(y.begin(), y.end());
            for (int i = 0; i + 1 < y.size(); i += 2) {
                cout << y[i] << " " << y[i + 1] << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}