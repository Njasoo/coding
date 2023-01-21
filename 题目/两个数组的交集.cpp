#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    unordered_map<int, int> hs;
    for (int i = 0; i < n; i++) {
        hs[a[i]]++;
    }
    vector<int> ans;
    for (int i = 0; i < m; i++) {
        if (hs[b[i]]) {
            ans.push_back(b[i]);
            hs[b[i]]--;
        }
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}