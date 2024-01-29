#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

#define db(x) cerr << (#x) << " = " << x << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    vector<int> new_a(n);
    int ans = 1e9;
    for (int i = -1; i <= 1; i++) {
        new_a[0] = a[0] + i;
        for (int j = -1; j <= 1; j++) {
            new_a[1] = a[1] + j;
            bool flag = true;
            int d = new_a[1] - new_a[0];
            int cnt = 0;
            if (i) cnt++;
            if (j) cnt++;
            for (int k = 2; k < n; k++) {
                new_a[k] = new_a[k - 1] + d;
                if (abs(new_a[k] - a[k]) > 1) {
                    flag = false;
                    break;
                } else {
                    if (new_a[k] != a[k]) cnt++;
                }
            }
            if (flag) {
                ans = min(ans, cnt);
            }
        }
    }
    if (ans != (int) 1e9) {
        cout << ans << '\n';
    } else {
        cout << "-1\n";
    }
    return 0;
}