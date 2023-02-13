#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int base2len(long long x) {
    int res = 0;
    while (x) {
        x /= 2;
        res++;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n, x;
        cin >> n >> x;
        // bitset<64> bn = n, bx = x;
        // debug(bn);
        // debug(bx);
        if (n == 0 && x == 0) {
            cout << n << '\n';
            continue;
        }
        if (x == 0) {
            int lenn = base2len(n);
            cout << (1LL << lenn) << '\n';
            continue;
        }
        if (x > n) {
            cout << "-1\n";
        } else if (x == n) {
            cout << n << '\n';
        } else {
            if (x % 2 == 1) {
                cout << "-1\n";
                continue;
            }
            vector<int> bitsn, bitsx;
            long long tempn = n, tempx = x;
            while (tempn) {
                bitsn.push_back(tempn % 2);
                tempn /= 2;
            }
            while (tempx) {
                bitsx.push_back(tempx % 2);
                tempx /= 2;
            }
            if (bitsn.size() != bitsx.size()) {
                cout << "-1\n";
                continue;
            }
            bool flag = 1;
            for (int i = 0; i < bitsn.size(); i++) {
                if (bitsx[i] == 1 && bitsn[i] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) {
                cout << "-1\n";
                continue;
            }
            // cout << "Hello\n";
            int highn = 100;
            int cntnbits = 0;
            for (int i = bitsn.size() - 2; i >= 0; i--) {
                if (bitsn[i] == 1 && highn == 100) {
                    highn = i;
                }
                cntnbits += bitsn[i];
            }
            int lowx = 100;
            for (int i = 0; i < bitsx.size() - 1; i++) {
                if (bitsx[i] == 1) {
                    lowx = i;
                    break;
                }
            }
            if (highn >= lowx) {
                cout << "-1\n";
                continue;
            }
            int lenn = base2len(n);
            if (highn + 1 == lenn - 1) {
                cout << "-1\n";
                continue;
            }
            long long ans = 1 << (lenn - 1);
            cout << (ans | (1 << (highn + 1))) << '\n';
        }
    }
    return 0;
}