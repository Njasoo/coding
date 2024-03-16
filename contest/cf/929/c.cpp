#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    int t = l;
    set<int> s;
    while (true) {
        int t = l;
        while (true) {
            s.insert(t);
            if (t % b != 0) {
                break;
            }
            t /= b;
        }
        if (l % a != 0) {
            break;
        }
        l /= a;
    }
    cout << s.size() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
    return 0;
}