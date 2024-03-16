#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

// 先找最大的数mx，与mx互补的数一定存在

char ask(int a, int b, int c, int d) {
    cout << "? " << a << " " << b << " " << c << " " << d << endl;
    char res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 1; i < n; i++) {
        char res = ask(mx, mx, i, i);
        if (res == '<') {
            mx = i;
        }
    }
    int y = 0;
    for (int i = 1; i < n; i++) {
        char res = ask(i, mx, y, mx);
        if (res == '>' || (res == '=' && ask(i, i, y, y) == '<')) {
            y = i;
        }
    }
    cout << "! " << mx << " " << y << endl;
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