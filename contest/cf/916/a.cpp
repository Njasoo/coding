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
        string s;
        cin >> s;
        int cnt[26] {};
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'A']++;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] >= i + 1) {
                ans++;
            }
        }
        cout << ans << '\n';
    }   
    return 0;
}