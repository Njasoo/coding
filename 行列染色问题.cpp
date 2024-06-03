#include <bits/stdc++.h>

using namespace std;

long long T[200005], A[200005], X[200005], tag_row[200005], tag_col[200005], cnt[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long H, W, M;
    cin >> H >> W >> M;
    long long max_color = 0;
    for (int i = 1; i <= H; i++) {
        tag_row[i] = -1;
    }
    for (int j = 1; j <= W; j++) {
        tag_col[j] = -1;
    }
    for (int i = 1; i <= M; i++) {
        cin >> T[i] >> A[i] >> X[i];
        max_color = max(max_color, X[i]);
    }
    long long cnt_row = H, cnt_col = W;
    for (int i = M; i >= 1; i--) {
        if (T[i] == 1) {
            if (tag_row[A[i]] == -1) {
                tag_row[A[i]] = X[i];
                cnt[X[i]] += cnt_col;
                if (cnt_col)
                    cnt_row--;
            }
        } else {
            if (tag_col[A[i]] == -1) {
                tag_col[A[i]] = X[i];
                cnt[X[i]] += cnt_row;
                if (cnt_row)
                    cnt_col--;
            }
        }
    }
    cnt[0] += cnt_row * cnt_col;
    vector<pair<int, long long>> ans;
    for (int i = 0; i <= max_color; i++) {
        if (cnt[i]) {
            ans.push_back({i, cnt[i]});
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x << " " << y << '\n';
    }
    return 0;
}