#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int cnt[26] {};
        string ans = "";
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] == a) {
                    ans += char(j + 'a');
                    cnt[j]++;
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}