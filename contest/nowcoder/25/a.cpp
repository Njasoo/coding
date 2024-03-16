#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }   
    string s;
    cin >> s;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            ans += a[i];
        } else {
            ans += max(5, a[i] / 100);
        }
    }
    cout << ans << '\n';
    return 0;
}