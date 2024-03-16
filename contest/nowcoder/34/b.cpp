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
    int pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) {
            pos = i;
        }
    }   
    sort(a.begin(), a.end());
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << "0\n";
        return 0;
    }
    cout << "1\n";
    cout << pos + 1 << " " << n << '\n';
    return 0;
}