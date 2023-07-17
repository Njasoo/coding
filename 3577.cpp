#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int a[N], b[N], tag[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tag[a[i]] = 1;
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        tag[b[i]] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!tag[a[i] + b[j]]) {
                cout << a[i] << " " << b[j] << '\n';
                return 0;
            }
        }
    }
    return 0;
}