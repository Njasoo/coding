#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        if (isalpha(s[i])) {
            for (char c : {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'}) {
                if (c == s[i]) {
                    cout << "YES\n";
                    return 0;
                }
            }
            break;
        }
    }   
    cout << "NO\n";
    return 0;
}