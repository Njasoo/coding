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

// 每个月份要么转s元，要么亏d元

const int N = 15;
long long mark[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long s, d;
    while (cin >> s >> d) {
        for (int i = 1; i <= 12; i++) {
            mark[i] = s;
        }
        for (int i = 1; i <= 8; i++) {
            long long cur_sum = 0;
            for (int j = 1; j <= 5; j++) {
                cur_sum += mark[i + j - 1];
            }
            if (cur_sum < 0) continue;
            for (int j = 5; j >= 1; j--) {
                mark[i + j - 1] = -d;
                cur_sum -= s + d;
                if (cur_sum < 0) break;
            }
        }
        long long tot = 0;
        for (int i = 1; i <= 12; i++) {
            tot += mark[i];
        }
        if (tot > 0) {
            cout << tot << '\n';
        } else {
            cout << "Deficit\n";
        }
    }
    return 0;
}