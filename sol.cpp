#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = 3;
    if (n == s.size()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}