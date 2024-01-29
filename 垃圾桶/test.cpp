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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        int min_cost = 1e9;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans += a[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> f[i][j];
            }
        }
    }
    return 0;
}