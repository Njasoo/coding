#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n < 0) {
        cout << "Negative Number\n";
    } else {
        if (n % 2) {
            cout << "Odd Number\n";
        } else {
            cout << "Even Number\n";
        }
    }
    return 0;
}