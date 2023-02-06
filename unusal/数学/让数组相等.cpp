#include <bits/stdc++.h>

using namespace std;

int a[200005];

/*
除了个位为5或0的, 其他数字都会进入2 -> 4 -> 8 -> 6的循环
个位为2的, + 2 + 4 + 8 + 6 == 20, 所以20后个位还是等于2
对于不是5和0的, 先把个位全部变成2
先检查所有元素是否相等, 因为此时可能所有元素都被10整除
然后再看所有元素 % 20是否都等于2或12, 也就是说2和12不能共存
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] % 10 == 5) {
                a[i] += 5;
            } else if (a[i] % 10 != 0) {
                while (a[i] % 10 != 2) {
                    a[i] += a[i] % 10;
                }
            }
        }
        sort(a + 1, a + 1 + n);
        if (a[1] == a[n]) {
            cout << "YES" << '\n';
        } else {
            int ok = 1;
            int check = a[1] % 20;
            if (check != 2 && check != 12) {
                cout << "NO" << '\n';
                continue;
            }
            for (int i = 2; i <= n; i++) {
                if (a[i] % 20 != check) {
                    ok = 0;
                    break;
                }
            }
            cout << (ok ? "YES" : "NO") << '\n';
        }
    }      
    return 0;
}