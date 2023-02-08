#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double d;
    cin >> d;
    cout << fixed << setprecision(2) << fabs(d) << " ";
    cout << fixed << setprecision(0) << floor(d) << " ";
    cout << fixed << setprecision(0) << ceil(d) << " ";
    cout << fixed << setprecision(0) << round(d) << " ";
    cout << fixed << setprecision(2) << pow(d, 5) << '\n';
    return 0;
}