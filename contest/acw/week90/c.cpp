#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " " << x << endl
const int N = 55;
string suf[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    int len = 0;
    bool flag = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (t[t.size() - 1 - (i - 1) + j] != t[j]) {
                len = i - 1;
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    string temp = t.substr(len);
    // debug(temp);
    cout << t;
    for (int i = 1; i < k; i++) {
        cout << temp;
    }
    cout << '\n';
    return 0;
}