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

// 每一次的钱都尽量接近c，先用大的面额，然后再用小的补上空缺

const int N = 25;
struct Node {
    long long v, b;
} t[N];
int cnt[N];

bool cmp(Node i, Node j) {
    return i.v < j.v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> t[i].v >> t[i].b;
    }  
    sort(t + 1, t + 1 + n, cmp);
    long long ans = 0;
    for (int i = n; i >= 1; i--) {
        // debug(i, t[i].v);
        if (t[i].v >= c) { // 面值大过c的直接一张支付就行
            ans += t[i].b;
            t[i].b = 0; // 记得清零
        }
    }
    // debug(ans);
    while (1) {
        memset(cnt, 0, sizeof cnt);
        long long temp_c = c;
        for (int i = n; i >= 1; i--) {
            if (t[i].b) {
                long long temp_cnt = min(temp_c / t[i].v, t[i].b); // 不超过c可以付多少张
                cnt[i] = temp_cnt;
                temp_c -= temp_cnt * t[i].v;
                if (temp_c == 0) break;
            }
        }
        if (temp_c > 0) {
            for (int i = 1; i <= n; i++) {
                if (cnt[i] < t[i].b && temp_c > 0) {
                    if ((t[i].b - cnt[i]) * t[i].v < temp_c) {
                        cnt[i] += (t[i].b - cnt[i]);
                        temp_c -= t[i].v * (t[i].b - cnt[i]);
                        continue;
                    }
                    if (temp_c <= 0) break;
                    long long L = 1, R = t[i].b - cnt[i];
                    long long bans = 1;
                    while (L <= R) {
                        long long mid = (L + R) / 2;
                        if (t[i].v * mid >= temp_c) {
                            R = mid - 1;
                            bans = mid;
                        } else {
                            L = mid + 1;
                        }
                    }
                    temp_c -= t[i].v * bans;
                    cnt[i] += bans;
                    if (temp_c <= 0) break;
                }
                if (temp_c <= 0) break;
            }
        }
        if (temp_c > 0) break;
        // 计算现在这个分配工资方案可以重复多少次
        long long mn_fre = 1e18;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) {
                mn_fre = min(mn_fre, t[i].b / cnt[i]);
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     cout << cnt[i] << " \n"[i == n];
        // }
        // system("pause");
        // debug(mn_fre);
        // for (int i = 1; i <= n; i++) {
        //     debug(i, cnt[i]);
        // }
        ans += mn_fre;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) {
                t[i].b -= cnt[i] * mn_fre;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}