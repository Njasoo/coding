#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, s;
    cin >> m >> s;
    if (m == 1 && s == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (m * 9 < s || s == 0) {
        cout << "-1 -1\n";
        return 0;
    }
    int nows = s;
    for (int i = 1; i <= m; i++) {
        int now = 0 + (i == 1);
        while ((nows - now) > 9 * (m - i)) {
            now++;
        }
        nows -= now;
        cout << now;
    }
    cout << " ";
    nows = s;
    for (int i = 1; i <= m; i++) {
        int now = 0 + (i == 1);
        while ((nows - now) > 0 && now < 9) {
            now++;
        }
        nows -= now;
        cout << now;
    }
    cout << '\n';
    return 0;
}