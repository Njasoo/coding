#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " = " << (x) << endl
#define dbp(x, y) cerr << "(" << #x << ", " << #y << ") = " << "(" << (x) << ", " << (y) << ")" << endl

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = n; i >= 0; i--) {
        cout << i << "\n";
    }
    return 0;
}