#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        if (y <= x)
        {
            cout << x << endl;
            continue;
        }
        cout << y + max(0, y - x - k) << endl;
    }
    return 0;
}