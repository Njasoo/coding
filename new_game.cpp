#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int l = 0, r = 0;
        int dis = 0;
        map<int, int> cnt;
        int ans = 0;
        while (l < n)
        {
            if (l == r)
            {
                cnt[a[l]]++;
                if (cnt[a[l]] == 1)
                    dis++;
            }
            while (r + 1 < n && (a[r + 1] - a[r] <= 1 && dis <= k))
            {
                r++;
                cnt[a[r]]++;
                if (cnt[a[r]] == 1)
                    dis++;
            }
            if (dis > k)
            {
                cnt[a[r]]--;
                dis--;
                r--;
            }
            ans = max(ans, r - l + 1);
            cnt[a[l]]--;
            l++;
        }
        cout << ans << endl;
    }
    return 0;
}