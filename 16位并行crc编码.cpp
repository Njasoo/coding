#include <bits/stdc++.h>

using namespace std;

vector<int> func(vector<int> d, vector<int> g) {
    int r = g.size() - 1;
    int n = d.size() - r;
    vector<int> R(r); // 过程的余数以及最终的答案
    for (int i = 0; i < r; i++) {
        R[i] = d[i];
    }
    int last_num = r - 1; // 最右边的寄存器所存储的数据的位置下标
    while (last_num < n + r - 1) {
        // 先判断最高位是否为1
        int first_digit = R[0];
        // 最高位运算后必然为零而且会被丢掉, 所以先左移再和生成多项式进行异或运算
        for (int i = 0; i < r - 1; i++) {
            R[i] = R[i + 1];
        }
        R[r - 1] = d[++last_num];
        if (first_digit == 1) {
            for (int i = 0; i < r; i++) {
                R[i] ^= g[i + 1];
                assert(R[i] == 1 || R[i] == 0);
            }
        }
    }
    return R;
}

string calcBase16(int x) {
    map<int, char> mp;
    for (int i = 0; i < 16; i++) {
        if (i < 10) {
            mp[i] = i + '0';
        } else {
            mp[i] = char('a' + i - 10);
        }
    }
    string res;
    while (x) {
        res += mp[x % 16];
        x /= 16;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 16, r = 5;
    // cin >> n >> r;
    vector<int> g = {1, 0, 1, 0, 0, 1};

    set<int> S;

    for (int i = 0; i < n; i++) {
        vector<int> d(n + r, 0);
        d[i] = 1;
        auto res = func(d, g);
        for (auto x : res) {
            cout << x;
        }
        cout << " for " << 16 - i;
        int cnt = 0;
        for (int i = 0; i < r; i++) {
            cnt = cnt * 2 + res[i];
        }
        S.insert(cnt);
        string cntBase16 = calcBase16(cnt);
        cout << " which is " << cnt << "(" << cntBase16 << ")" << '\n';
    }

    assert((int) S.size() == n);

    // vector<int> g = {1, 0, 0, 1, 0, 1};
    // vector<int> g = {1, 1, 1, 1, 1, 1};
    // vector<int> nums = {0x18, 0xc, 0x6, 0x3, 0x13, 0x1b, 0x1f, 0x1d, 0x1c, 0xe, 0x7, 0x11, 0x1a, 0xd, 0x14, 0xa};
    // assert((int) nums.size() == n);
    // for (int mask = 0; mask < (1 << (r + 1)); mask++) {
    //     vector<int> g(r + 1);
    //     for (int i = 0; i <= r; i++) {
    //         if (mask >> i & 1) {
    //             g[i] = 1;
    //         }
    //     }
    //     vector<int> t(n);
    //     for (int i = 0; i < n; i++) {
    //         vector<int> d(n + r, 0);
    //         d[i] = 1;
    //         auto res = func(d, g);
    //         // for (auto x : res) {
    //         //     cout << x;
    //         // }
    //         // cout << " for " << 16 - i;
    //         int cnt = 0;
    //         for (int i = 0; i < r; i++) {
    //             cnt = cnt * 2 + res[i];
    //         }
    //         t[i] = cnt;
    //         // string cntBase16 = calcBase16(cnt);
    //         // cout << " which is " << cnt << "(" << cntBase16 << ")" << '\n';
    //     }
    //     bool flag = true;
    //     for (int i = 0; i < n; i++) {
    //         if (t[i] != nums[i]) {
    //             flag = false;
    //             break;
    //         }
    //     }
    //     if (!flag) {
    //         continue;
    //     }
    //     for (int i = 0; i < n; i++) {
    //         cout << " for i = " << 16 - i << " ";
    //         string cntBase16 = calcBase16(t[i]);
    //         cout << " which is " << t[i] << "(" << cntBase16 << ")" << '\n';
    //     }
    // }
    return 0;
}