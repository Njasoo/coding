#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        set<int> ina, inb;
        bool ok = true;
        for (int i = 1; i <= k; i++) {
            auto ita = binary_search(a.begin(), a.end(), i);
            auto itb = binary_search(b.begin(), b.end(), i);
            if (ita && !itb) {
                ina.insert(i);
                if (ina.size() > k / 2) {
                    ok = false;
                    break;
                }
            } else if (!ita && itb) {
                inb.insert(i);
                if (inb.size() > k / 2) {
                    ok = false;
                    break;
                }
            } else if (!ita && !itb) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}