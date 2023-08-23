#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cin >> f[i][j];
        }
    }
    bool chk = true;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (f[i][j] != j + 1) cnt++;
        }
        if (cnt == 0 || cnt == 2) continue;
        // cerr << "row_number: " << i << " cnt: " << cnt << endl;
        chk = false;
        break;
    }
    if (chk) {
        cout << "YES\n";
        return 0;
    }
    for (int mask = 0; mask < (1 << m); mask++) {
        if (__builtin_popcount(mask) != 2) continue;
        vector<int> swap_pos;
        for (int i = 0; i < m; i++) {
            if (mask >> i & 1) {
                swap_pos.push_back(i);
            }
        }
        // cerr << "(" << swap_pos[0] << ", " << swap_pos[1] << ")" << endl;
        auto origin = f;
        for (int i = 0; i < n; i++) {
            swap(f[i][swap_pos[0]], f[i][swap_pos[1]]);
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cerr << f[i][j] << " ";
        //     }
        //     cerr << endl;
        // }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (f[i][j] != j + 1) cnt++;
            }
            if (cnt == 0 || cnt == 2) continue;
            // cerr << "row_number: " << i << " cnt: " << cnt << endl;
            flag = false;
            break;
        }
        if (flag) {
            cout << "YES\n";
            return 0;
        }
        f = origin;
    }
    cout << "NO\n";
    return 0;
}