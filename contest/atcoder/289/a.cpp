#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    for (char c : s) {
        cout << (c == '1' ? '0' : '1');
    }
    cout << '\n';
    return 0;
}