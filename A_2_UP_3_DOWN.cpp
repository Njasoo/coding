#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    bool ok = 0;
    if (y >= x && y - x <= 2)
        ok = 1;
    if (y <= x && x - y <= 3)
        ok = 1;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}