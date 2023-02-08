#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int x, y;
void ex_gcd(int a, int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    ex_gcd(b, a % b);
    int tempx = x;
    x = y;
    y = tempx - a / b * y;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    x = (x % b + b) % b;
    cout << x << '\n';
    return 0;
}