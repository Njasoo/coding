#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if (c % __gcd(a, b)) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }  
    return 0;
}