#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const int N = 2e5 + 5;
string s[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((s[i].size() - s[j].size()) % 2)
                continue;
            string temp = s[i] + s[j];
            int cnt_1 = 0;
            int cnt_2 = 0;
            for (int k = 0; k < (int)temp.size() / 2; k++)
            {
                cnt_1 += temp[k] - '0';
            }
            for (int k = temp.size() / 2; k < (int)temp.size(); k++)
            {
                cnt_2 += temp[k] - '0';
            }
            if (cnt_1 == cnt_2)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}