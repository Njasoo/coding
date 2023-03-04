#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) <<endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        cout << (n % 4 ? "NO" : "YES") << '\n';   
    }
    return 0;
}