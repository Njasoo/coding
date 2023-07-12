#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int d[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        d[a]++, d[b + 1]--;
    }    
    for (int i = 1; i <= n; i++) {
        d[i] += d[i - 1];
        if (d[i] != 1) {
            cout << i << " " << d[i] << '\n';
            return 0;
        }
    }  
    cout << "OK\n";
    return 0;
}