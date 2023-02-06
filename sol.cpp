#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << x << endl
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N], b[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, w, h;
        cin >> n >> w >> h;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        int L = -INF, R = INF;
        for (int i = 1; i <= n; i++) {
            L = max(L, a[i] - b[i] - w + h);
            R = min(R, a[i] - b[i] + w - h);
        }
        cout << (L <= R ? "YES" : "NO") << '\n';
    }   
    return 0;
}