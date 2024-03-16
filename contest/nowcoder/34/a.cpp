#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "2\n";
        cout << a << "\n" << a << a << '\n';
    } else {
        cout << "4\n";
        cout << a << "\n" << b << "\n" << a << b << "\n" << b << a << "\n";
    }
    return 0;
}