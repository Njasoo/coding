#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0, ans2 = 0;
    int tag = 0;
    int cnt = 0;
    while (n)
    {
        cnt++;
        if (tag == 0 && n % 3 == 1)
        {
            tag = 1;
            ans2 = cnt;
        }
        n *= 2;
        if (n / 3 == 0)
        {
            if (n % 3 == 0)
                ans++;
        }
        n /= 3;
        ans++;
    }
    cout << ans << " " << ans2 << endl;
    return 0;
}