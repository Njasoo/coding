#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[4];
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    sort(a, a + 4);
    for (int i = 0; i < 3; i++) {
        if (a[i] == a[i + 1]) {
            cout << a[i] << "\n";
            break;
        }
    }
    return 0;
}