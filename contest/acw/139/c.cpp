#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cassert>
#include <map>
#include <numeric>
#include <iomanip>
#include <set>
#include <array>

using namespace std;

#define db(x) cerr << (#x) << " = " << x << " "
#define el cerr << endl

const int N = 2e5 + 5;
int a[N];
map<int, pair<int, vector<int>>> f;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]].second.push_back(i);
    }
    int max_len = 1, last_idx = 1;
    for (int i = 1; i <= n; i++) {
        int len = f[a[i]].first = f[a[i] - 1].first + 1;
        // db(len), el;
        if (len > max_len) {
            max_len = len;
            last_idx = i;
        }
    }
    int now_idx = last_idx;
    // db(last_idx), el;
    vector<int> ans;
    while (now_idx) {
        ans.push_back(now_idx);
        int l = 0, r = f[a[now_idx] - 1].second.size() - 1;
        int pos = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (f[a[now_idx] - 1].second[mid] < now_idx) {
                l = mid + 1;
                pos = mid;
            } else {
                r = mid - 1;
            }
        }
        if (pos == -1) {
            break;
        }
        now_idx = f[a[now_idx] - 1].second[pos];
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
    }
    return 0;
}