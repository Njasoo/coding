#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long ll;

int lg[100005], id[85][85];
vector<vector<int>> a, st1[18], st2[18];
vector<vector<int>> col_min, col_max;
int n, m;

void build(int cur_id) {
    lg[1] = 0;
    for (int i = 2; i <= m; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    for (int i = 1; i <= m; i++) {
        // db(col_max[i][cur_id]), el;
        // db(col_min[i][cur_id]), el;
        st1[0][cur_id][i] = col_max[i][cur_id];
        st2[0][cur_id][i] = col_min[i][cur_id];
    }
    for (int j = 1; j < 18; j++) {
        for (int i = 1; i + (1 << j) - 1 <= m; i++) {
            st1[j][cur_id][i] = max(st1[j - 1][cur_id][i], st1[j - 1][cur_id][i + (1 << (j - 1))]);
            st2[j][cur_id][i] = min(st2[j - 1][cur_id][i], st2[j - 1][cur_id][i + (1 << (j - 1))]);
        }
    }
}

ll query1(int cur_id, int l, int r) {
    int k = lg[r - l + 1];
    return max(st1[k][cur_id][l], st1[k][cur_id][r - (1 << k) + 1]);
}

ll query2(int cur_id, int l, int r) {
    int k = lg[r - l + 1];
    return min(st2[k][cur_id][l], st2[k][cur_id][r - (1 << k) + 1]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    a = vector<vector<int>>(n + 1, vector<int>(m + 1));
    for (int i = 0; i < 18; i++) {
        st1[i] = vector<vector<int>>(n * (n + 1) / 2 + 1, vector<int>(m + 1));
        st2[i] = vector<vector<int>>(n * (n + 1) / 2 + 1, vector<int>(m + 1));
    }
    col_min = vector<vector<int>>(m + 1, vector<int>(n * (n + 1) / 2 + 1));
    col_max = vector<vector<int>>(m + 1, vector<int>(n * (n + 1) / 2 + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int limit;
    cin >> limit;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int ii = i; ii <= n; ii++) {
            id[i][ii] = ++cnt;
            // build(id[i][ii]);
        }
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            int cur_min = 1e9;
            int cur_max = 0;
            for (int ii = i; ii <= n; ii++) {
                cur_min = min(cur_min, a[ii][j]);
                cur_max = max(cur_max, a[ii][j]);
                col_min[j][id[i][ii]] = cur_min;
                col_max[j][id[i][ii]] = cur_max;
                // db(col_min[j][id[i][ii]]), el;
                // db(col_max[j][id[i][ii]]), el;
            }
        }
    }
    for (int i = 1; i <= cnt; i++) {
        build(i);
    }
    int ans = 0;
    // db(query1(n * (n + 1) / 2, 1, m) - query2(n * (n + 1) / 2, 1, m)), el;
    for (int i = 1; i <= n; i++) {
        for (int ii = 1; ii <= n; ii++) {
            int l = 1, r = 1;
            int height = ii - i + 1;
            while (l <= m) {
                r = max(l, r);
                // assert(r >= l);
                while (r <= m && query1(id[i][ii], l, r) - query2(id[i][ii], l, r) <= limit) { // 当两行或以上的时候，一列不一定成立
                    r++;
                }
                // db(l), db(r - 1), el;
                ans = max(ans, height * (r - l));
                if (r == m + 1) {
                    break;
                }
                l++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}