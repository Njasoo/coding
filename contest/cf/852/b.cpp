#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int x, y;
        cin >> x >> y;
        vector<int> ans;
        for (int i = x; i > y; i--) {
            ans.push_back(i);
        }
        for (int i = y; i < x; i++) {
            ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (int x : ans) {
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}