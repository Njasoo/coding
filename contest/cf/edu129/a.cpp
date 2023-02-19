#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        int mxa = 0, mxb = 0;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            mxa = max(mxa, a);
        }
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            int b;
            cin >> b;
            mxb = max(mxb, b);
        }
        if (mxa >= mxb) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
        if (mxb >= mxa) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }   
    return 0;
}