#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;

int tag[105];

bool issq(long long x)
{
    long long sq = sqrt(x);
    return sq * sq == x;
}

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        long long a, b;
        cin >> a >> b;
        vector<int> factors;
        for (int i = 2; i <= a; i++)
        {
            while (a % i == 0)
            {
                a /= i;
                factors.push_back(i);
            }
        }
        if (a != 1)
            factors.push_back(a);
        for (auto x : factors)
        {
            cout << x << " ";
        }
        cout << endl;
        for (int i = 0; i < (int)factors.size(); i++)
        {
            if (issq(factors[i]))
            {
                tag[i] = 1;
            }
        }
        bool ok = 0;
        for (int mask = 0; mask < (1 << factors.size()); mask++)
        {
            int flag = 1;
            for (int i = 0; i < (int)factors.size(); i++)
            {
                if ((mask >> i & 1) == 1 && !tag[i])
                {
                    flag = 0;
                    break;
                }
            }
            if (!flag)
                continue;
            long long cnt_b = 1;
            for (int i = 0; i < (int)factors.size(); i++)
            {
                if (mask >> i & 1)
                {
                    cnt_b *= (long long)sqrt(factors[i]);
                }
                else
                {
                    cnt_b *= factors[i] * factors[i];
                }
            }
            if (cnt_b == b)
            {
                ok = 1;
                break;
            }
        }
        if (ok)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}