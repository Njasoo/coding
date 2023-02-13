#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 105;
int a[N];
bool ina[N], vis[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        ina[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (!ina[i]) {
            for (int j = i; j >= 1; j--) {
                if (vis[j]) break;
                vis[j] = 1;
                cout << j << " ";
            }
        }
    }
    cout << '\n';
    return 0;
}