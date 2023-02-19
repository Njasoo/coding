#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            cnt += j;
            if (cnt == n) {
                flag = true;
                for (int k = i; k <= j; k++) {
                    cout << k << " \n"[k == j];
                }
            }
        }
    }   
    if (!flag) {
        cout << "NULL\n";
    }
    return 0;
}