#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<pair<int, int>> t(n), ans;
        for (int i = 0; i < n; i++) {
            cin >> t[i].first;
        }
        for (int i = 0; i < n; i++) {
            cin >> t[i].second;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (t[j].first > t[j + 1].first || (t[j].first == t[j + 1].first && t[j].second > t[j + 1].second)) {
                    swap(t[j], t[j + 1]);
                    ans.push_back({j + 1, j + 2});
                }
            }
        }
        bool flag = 1;
        for (int i = 0; i < n - 1; i++) {
            if (t[i].first > t[i + 1].first || (t[i].second > t[i + 1].second)) {
                flag = 0;
                break;
            }
        }
        if (!flag) {
            cout << "-1\n";
        } else {
            cout << ans.size() << '\n';
            for (auto [x, y] : ans) {
                cout << x << " " << y << '\n';
            }
        }
    }   
    return 0;
}