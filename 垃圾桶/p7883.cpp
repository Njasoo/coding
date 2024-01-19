#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 4e5 + 5;
pair<long long, long long> p[N];
int y[N], deleted[N];

long long dis_2(int i, int j)
{
    return (p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second);
}

bool cmp(int i, int j)
{
    return p[i].second > p[j].second;
}

long long solve(int l, int r)
{
    if (l == r)
        return (long long)1e18;
    if (r - l == 1)
        return dis_2(l, r);
    int mid = (l + r) / 2;
    long long min_l = solve(l, mid);
    long long min_r = solve(mid + 1, r);
    long long d = min(min_l, min_r);
    for (int i = 1; i <= r; i++)
    {
        if (dis_2(mid, i) > d)
        {
            deleted[i] = 1;
        }
    }
    long long res = d;
    return res;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        y[i] = i;
    }
    sort(y + 1, y + 1 + n, cmp);
    cout << solve(1, n) << endl;
    return 0;
}