#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += (1 << (s.size() - 1 - i)) * (s[i] - '0');
    }   
    cout << ans << '\n';
    return 0;
}