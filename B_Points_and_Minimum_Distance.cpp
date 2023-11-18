#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

long long a[1005];

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + 2 * n);
        long long ans = a[n] - a[1] + a[2 * n] - a[n + 1];
        cout << ans << endl;
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " " << a[i + n] << endl;
        }
    }
    return 0;
}