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
    for (int i = 2; i <= n; i += 2) {
        cout << i << " ";
    }   
    for (int i = 1; i <= n; i += 2) {
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}