#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ans = 0;
    for (int i = 0; i < 6; i++) {
        int a;
        cin >> a;
        ans += a;
    }
    cout << ans << '\n';
    return 0;
}