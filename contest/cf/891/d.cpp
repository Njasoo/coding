#include <bits/stdc++.h>

using namespace std;

// edge from u to v exist if a[u] - b[u] >= a[v] - b[v]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a[i] -= b;
        }
        int mx = *max_element(a.begin(), a.end());
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (a[i] == mx) ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (auto x : ans) {
            cout << x + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}