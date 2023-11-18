#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int N = 1e5 + 5;
long long v[N], a[N];

int main()
{
    long long n, d;
    cin >> n >> d;
    long long now_dis = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        now_dis += v[i];
    }
    long long ans = 1e18, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i == n)
            break;
        cout << "sum=" << sum << " "
             << "剩下的花费=" << (now_dis / d + (now_dis % d != 0)) * a[i] << endl;
        ans = min(ans, sum + (now_dis / d + (now_dis % d != 0)) * a[i]);
        sum += (v[i] / d + (v[i] % d != 0)) * a[i];
        now_dis -= v[i];
    }
    cout << ans << endl;
    return 0;
}