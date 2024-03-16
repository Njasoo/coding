#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }   
    sort(a.begin(), a.end());
    if (round(1.0 * s / n) == 5.0) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        s += 5 - a[i];
        if (round(1.0 * s / n) == 5.0) {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}