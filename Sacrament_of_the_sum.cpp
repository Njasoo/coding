#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int N = 50005;
int a[N], b[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
        int target = 10000 - a[i];
        int l = 1, r = m;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (b[mid] == target) {
                ok = 1;
                break;
            } else if (b[mid] > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ok) break;
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}