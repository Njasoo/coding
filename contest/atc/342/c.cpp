#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<int> f(26);
    iota(f.begin(), f.end(), 0);
    while (Q--) {
        char c, d;
        cin >> c >> d;
        for (int i = 0; i < 26; i++) {
            if (f[i] == c - 'a') {
                f[i] = d - 'a';
            }
        }
    }   
    for (auto c : S) {
        cout << char(f[c - 'a'] + 'a');
    }
    cout << '\n';
    return 0;
}