#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int cnt = a + (i - a % n + n) % n;
        ans = min(ans, cnt);
    }
    cout << (ans % n) + 1 << '\n';
    return 0;
}