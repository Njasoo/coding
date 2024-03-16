#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'N' && b[i] == 'Y') {
            ans += 2;
            continue;
        }
        ans += (a[i] == 'Y') * 2;
        ans += (b[i] == 'Y');
    }
    cout << ans << '\n';
    return 0;
}