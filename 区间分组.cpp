#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end());
    vector<bool> mark(n);
    mark[0] = true;
    int i = 0, j = 1;
    while (i < n) {
        while (j < n && p[j].first <= p[i].second) {
            j++;
        }
        if (j == n) {
            break;
        }
        mark[j] = true;
        i = j;
    }
    vector<pair<int, int>> tp;
    for (i = 0; i < n; i++) {
        if (!mark[i]) {
            tp.emplace_back(p[i]);
        }
    }
    for (i = 0; i < (int)tp.size() - 1; i++) {
        if (tp[i + 1].first <= tp[i].second) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}