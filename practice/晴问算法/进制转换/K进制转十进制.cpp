#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res *= a;
        b >>= 1;
        a *= a;
    }
    return res;
}
int match[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int k;
    cin >> s >> k;   
    int ans = 0;
    for (int i = 'A'; i <= 'F'; i++) {
        match[i - 'A'] = i - 'A' + 10;
    }
    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            ans += power(k, s.size() - 1 - i) * (s[i] - '0');
        } else {
            ans += power(k, s.size() - 1 - i) * match[s[i] - 'A'];
        }
    }
    cout << ans << '\n';
    return 0;
}