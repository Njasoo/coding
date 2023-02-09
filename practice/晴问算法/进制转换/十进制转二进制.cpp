#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
void solve(int n) {
    if (n >= 2) solve(n / 2);
    cout << n % 2;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    solve(n);   
    return 0;
}