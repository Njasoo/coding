#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

const int N = 5e5 + 5;
char s[N], t[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s + 1 >> t + 1;
    int lens = strlen(s + 1);
    int lent = strlen(t + 1);
    for (int i = 1; i <= lens; i++) {
        if (s[i] != t[i]) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << lent << '\n';
    return 0;
}