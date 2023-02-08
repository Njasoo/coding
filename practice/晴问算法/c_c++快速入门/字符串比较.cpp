#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    if (a < b) cout << "<\n";
    else if (a == b) cout << "=\n";
    else cout << ">\n";   
    return 0;
}