#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    switch(n) {
    case 0:
        cout << "Zero\n";
        break;
    case 1:
        cout << "One\n";
        break;
    case 2:
        cout << "Two\n";
        break;
    case 3:
        cout << "Three\n";
        break;
    case 4:
        cout << "Four\n";
        break;
    case 5:
        cout << "Five\n";
        break;
    default:
        cout << "Greater than 5\n";
        break;
    }   
    return 0;
}