#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<int, array<int, 2>> ls;
    map<int, bool> del;
    int q;
    cin >> q;
    int le = -1;
    while (q--) {
        int o;
        cin >> o;
        if (o == 1) {
            int x, y;
            cin >> x >> y;
            if (y == 0) {
                if (le == -1) {
                    le = x;
                } else {
                    ls[x][1] = le;
                    ls[le][0] = x;
                    le = x;
                }
                continue;
            }
            int y_r = ls[y][1];
            ls[y][1] = x;
            ls[x][0] = y;
            ls[y_r][0] = x;
            ls[x][1] = y_r;
        } else {
            int x;
            cin >> x;
            del[x] = true;
            int x_l = ls[x][0];
            int x_r = ls[x][1];
            ls[x_l][1] = x_r;
            ls[x_r][0] = x_l;
        }
    }
    int now = -1;
    for (auto [x, y] : ls) {
        if (y[0] == 0 && !del[x] && x) {
            now = x;
            break;
        }
    }
    vector<int> ans;
    while (now) {
        ans.push_back(now);
        now = ls[now][1];
    }
    cout << ans.size() << '\n';
    for (int x : ans) {
        cout << x << " ";
    }
    cout << '\n';
    return 0;
}