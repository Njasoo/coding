#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, k;
    cin >> n >> x >> k;
    int tot = n * x;
    int cnt = tot / k;
    int cur = x;
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        int need = k;
        int b = 0;
        while (need > 0) {
            if (need >= cur) {
                if (cur == x) {
                    need -= cur;
                    b++;
                } else {
                    need -= cur;
                    cur = x;
                }
            } else {
                if (cur == x) {
                    b++;
                }
                cur -= need;
                need = 0;
            }
        }
        // db(cur), el;
        cout << b << " ";
    }
    cout << "\n";
    return 0;
}