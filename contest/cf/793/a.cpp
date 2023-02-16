#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = ' ' + s;
        if (n % 2 == 0) {
            char start = s[n / 2];
            int l = n / 2, r = n / 2 + 1;
            int cnt = 0;
            while (s[l] == s[r] && s[l] == start && l >= 1 && r <= n) {
                l--, r++;
                cnt++;
            }
            cout << cnt * 2 << '\n';
        } else {
            char start = s[n / 2 + 1];
            int l = n / 2 + 1, r = n / 2 + 1;
            int cnt = 0;
            while (s[l] == s[r] && s[l] == start && l >= 1 && r <= n) {
                l--, r++;
                cnt++;
            }
            cout << cnt * 2 - 1 << '\n';
        }
    }   
    return 0;
}