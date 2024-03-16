#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

// 分成两部分，前面保留的，和后面不动的
// 前面保留一个，对答案的贡献就是前两位当中不同的字符数量

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> S;
    ll ans = 0;
    for (char c : s) {
        S.insert(c);
        ans += S.size();
    }
    cout << ans << '\n';
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