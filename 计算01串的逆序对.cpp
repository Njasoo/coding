#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    array<vector<int>, 2> pos;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';
        pos[c].push_back(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int p = upper_bound(all(pos[0]), i) - pos[0].begin();
            ans += sz(pos[0]) - p;
        }
    }
    cout << ans << "\n";
    return 0;
}