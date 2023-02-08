#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << a / b << '\n';
    cout << fixed << setprecision(2) << 1.0 * a / b << '\n';   
    return 0;
}