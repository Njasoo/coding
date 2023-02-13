#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    if (a + 1 == b || (a == 1 && b == 10)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
    return 0;
}