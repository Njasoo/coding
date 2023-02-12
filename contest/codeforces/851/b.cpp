#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string s;
        cin >> s;
        vector<int> nums;
        for (int i = 0; i < s.size(); i++) {
            nums.push_back(s[i] - '0');
        }
        string a, b;
        int round = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2) {
                if (round) {
                    a += (nums[i] / 2 + '0');
                    b += (nums[i] / 2 + 1 + '0');
                } else {
                    b += (nums[i] / 2 + '0');
                    a += (nums[i] / 2 + 1 + '0');
                }
                round ^= 1;
            } else {
                a += (nums[i] / 2 + '0');
                b += (nums[i] / 2 + '0');
            }
        }
        while (a[0] == '0' && a.size() > 1) a.erase(a.begin());
        while (b[0] == '0' && b.size() > 1) b.erase(b.begin());
        cout << a << " " << b << '\n';
    }   
    return 0;
}