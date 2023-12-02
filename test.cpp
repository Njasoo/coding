#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

#ifdef LOCAL
#include "d:/coding/debug.h"
#else
#define debug(...) 114514
#endif

const int N = 1005;
long long f[N], d[N], t[N], sum[N], ans[N], real_ans[N];
long long n, h, tot_ans, max_ans;
struct Node {
    long long _f, _d, _id;

    bool operator<(const Node& rhs) const {
        if (_f == rhs._f) {
            return _id > rhs._id;
        }
        return _f < rhs._f;
    }
};

long long solve(int num) {
    long long now_time = h;
    now_time -= sum[num - 1];
    priority_queue<Node> q;
    for (int i = 1; i <= num; i++) {
        Node temp;
        temp._f = f[i];
        temp._d = d[i];
        temp._id = i;
        q.push(temp);
    }
    long long res = 0;
    while (now_time > 0 && !q.empty()) {
        Node u = q.top();
        q.pop();
        long long _f = u._f, _d = u._d, _id = u._id;
        // debug(_f);
        now_time--;
        ans[_id]++;
        res += _f;
        Node temp;
        temp._f = max(_f - _d, 0LL);
        temp._d = _d;
        temp._id = _id;
        q.push(temp);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int first = 1;
    while (cin >> n) {
        if (n == 0) break;
        if (!first) {
            cout << "\n\n";
            first = 0;
        }
        max_ans = 0;
        cin >> h;
        h = h * 60 / 5;
        // debug(h);
        // f[i] - t / 5 * d[i] >= 0
        // t / 5 * d[i]  <= f[i]
        // t <= f[i] / d[i] * 5
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }
        for (int i = 1; i < n; i++) {
            cin >> t[i];
            sum[i] = sum[i - 1] + t[i];
        }
        for (int i = 1; i <= n; i++) {
            memset(ans, 0, sizeof ans);
            int res = solve(i);
            // debug(i, res);  
            // debug(res);
            if (res > max_ans) {
                max_ans = res;
                for (int j = 1; j <= n; j++) {
                    real_ans[j] = ans[j];
                }   
            } else if (res == max_ans) {
                bool ok = 0;
                for (int j = 1; j <= n; j++) {
                    if (ans[j] == real_ans[j]) {
                        continue;
                    } else if (ans[j] > real_ans[j]) {
                        ok = 1;
                        break;
                    } else if (ans[j] < real_ans[j]) {
                        break;
                    }
                }
                if (ok) {
                    for (int j = 1; j <= n; j++) {
                        real_ans[j] = ans[j];
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            cout << real_ans[i] * 5 << ", ";    
        }
        cout << real_ans[n] * 5 << '\n';
        cout << "Number of fish expected: " << max_ans;
    }   
    return 0;
}