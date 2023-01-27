#include <bits/stdc++.h>
using namespace std;
// 贪心，按照能隔开的人数排序
const int N = 2e3 + 5;
struct node {
    int x1, y1, x2, y2;
}t[N];
struct node2 {
    int id, fre;
}row[N], col[N];
bool cmp(node2 i, node2 j) {
    return i.fre > j.fre;
}
int ans_row[N], ans_col[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, l, d;
    cin >> n >> m >> k >> l >> d;
    for (int i = 1; i <= n; i++) row[i].id = i;
    for (int i = 1; i <= m; i++) col[i].id = i;
    for (int i = 1; i <= d; i++) {
        cin >> t[i].x1 >> t[i].y1 >> t[i].x2 >> t[i].y2;
    }       
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= d; j++) {
            if (t[j].x1 <= i && i < t[j].x2) {
                row[i].fre++;
            } else if (t[j].x2 <= i && i < t[j].x1) {
                row[i].fre++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            if (t[j].y1 <= i && i < t[j].y2) {
                col[i].fre++;
            } else if (t[j].y2 <= i && i < t[j].y1) {
                col[i].fre++;
            }
        }
    }
    sort(row + 1, row + 1 + n, cmp);
    sort(col + 1, col + 1 + m, cmp);
    int idx1 = 0, idx2 = 0;
    for (int i = 1; i <= k; i++) {
        ans_row[++idx1] = row[i].id;
    }
    for (int i = 1; i <= l; i++) {
        ans_col[++idx2] = col[i].id;
    }
    sort(ans_row + 1, ans_row + 1 + idx1);
    sort(ans_col + 1, ans_col + 1 + idx2);
    for (int i = 1; i <= k; i++) {
        cout << ans_row[i];
        if (i != k) cout << " ";
    }
    cout << '\n';
    for (int i = 1; i <= l; i++) {
        cout << ans_col[i];
        if (i != l) cout << " ";
    }
    return 0;
}