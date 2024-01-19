#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 55;
int f[N], d[N], t[N], sum[N], cur_ans[N], ans[N];
struct Node {
    int _id, _f, _d;

    bool operator<(const Node& rhs) const {
        if (_f == rhs._f) return _id > rhs._id;
        return _f < rhs._f;
    }
};

int solve(int n, int h) {
    int now_time = h;
    now_time -= sum[n - 1];
    priority_queue<Node> q;
    for (int i = 1; i <= n; i++) {
        Node temp;
        temp._id = i, temp._f = f[i], temp._d = d[i];
        q.push(temp);
    }
    int res = 0;
    memset(cur_ans, 0, sizeof cur_ans);
    while (now_time >= 5) {
        Node u = q.top();
        q.pop();
        res += u._f;
        now_time -= 5;
        u._f = max(0, u._f - u._d);
        cur_ans[u._id] += 5;
        q.push(u);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        int h;
        cin >> h;
        memset(ans, 0, sizeof ans);
        h *= 60; // 转成分钟
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> t[i]; // t[i] 到 t[i + 1]个湖
            t[i] *= 5;
            sum[i] = sum[i - 1] + t[i];
        }
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            int res = solve(i, h);
            if (res == mx) {
                mx = res;
                bool ok = 0;
                for (int j = 1; j <= n; j++) {
                    if (cur_ans[j] == ans[j]) {
                        continue;
                    } else if (cur_ans[j] > ans[j]) {
                        ok = 1;
                        break;
                    } else if (cur_ans[j] < ans[j]) {
                        break;
                    }
                }
                if (ok) {
                    for (int j = 1; j <= n; j++) {
                        ans[j] = cur_ans[j];
                    }
                }
            } else if (res > mx) {
                mx = res;
                for (int j = 1; j <= n; j++) {
                    ans[j] = cur_ans[j];
                }
            }
        }
        for (int i = 1; i < n; i++) {
            cout << ans[i] << ", ";
        }
        cout << ans[n] << '\n';
        cout << "Number of fish expected: " << mx << "\n\n";
    }
    return 0;
}