#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = n;; i++) {
        int baiwei = (i / 100) % 10;
        int shiwei = (i / 10) % 10;
        int gewei = i % 10;
        if (baiwei * shiwei == gewei) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}