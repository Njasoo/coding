#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    if (s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 'a' + 'A';
    }
    cout << s << '\n';
    return 0;
}