#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    map<char, int> cnt;
    cin >> S;
    for (auto c : S) {
        cnt[c]++;
    }
    for (auto [x, y] : cnt) {
        if (y == 1) {
            for (int i = 0; i < S.size(); i++) {
                if (S[i] == x) {
                    cout << i + 1 << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}