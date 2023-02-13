#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int ans = s.size();
    for (int i = s.size() - 1; i >= 0; i--) {
        if (i >= 1 && s[i] == '0' && s[i - 1] == '0') {
            ans--;
            i--;
        }
    }   
    cout << ans << '\n';
    return 0;
}