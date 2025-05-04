#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

const int N = 2e5 + 5;
int p[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        if (n < 5) {
            cout << "-1\n";
            continue;
        }
        // 1 3 2 4
        // 1 3 5 2 4 6
        // 1 2 3 4 5
        // 1 3 5 4 2
        if (n % 2 == 0) {
            p[n / 2] = 5, p[n / 2 + 1] = 4;
            int nowOdd = 1;
            for (int i = 1; i < n / 2; i++) {
                if (nowOdd == 5) {
                    nowOdd += 2;
                }
                p[i] = nowOdd;
                nowOdd += 2;
            }
            int nowEven = 2;
            for (int i = n / 2 + 2; i <= n; i++) {
                if (nowEven == 4) {
                    nowEven += 2;
                }
                p[i] = nowEven;
                nowEven += 2;
            }
            for (int i = 1; i <= n; i++) {
                cout << p[i] << " \n"[i == n];
            }
        } else {
            p[n / 2 + 1] = 5, p[n / 2 + 2] = 4;
            int nowOdd = 1;
            for (int i = 1; i <= n / 2; i++) {
                if (nowOdd == 5) {
                    nowOdd += 2;
                }
                p[i] = nowOdd;
                nowOdd += 2;
            }
            int nowEven = 2;
            for (int i = n / 2 + 3; i <= n; i++) {
                if (nowEven == 4) {
                    nowEven += 2;
                }
                p[i] = nowEven;
                nowEven += 2;
            }
            for (int i = 1; i <= n; i++) {
                cout << p[i] << " \n"[i == n];
            }
        }
    }   
    return 0;
}