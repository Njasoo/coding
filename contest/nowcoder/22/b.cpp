#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            int j = i + 2;
            int cnt = 2;
            while (j + 1 < n && s[j] == s[j + 1]) {
                cnt += 2;
                j += 2;
            }
            i = j;
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
    return 0;
}