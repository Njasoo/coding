#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> t(n);
        for (int i = 0; i < n; i++) {
            t[i].first = nums[i];
            t[i].second = i;
        }
        sort(t.begin(), t.end());
        vector<int> ans;
        int l = 0, r = n - 1;
        while (l < r) {
            if (t[l].first + t[r].first == target) {
                ans.push_back(t[l].second);
                ans.push_back(t[r].second);
                break;
            } else if (t[l].first + t[r].first > target) {
                r--;
            } else {
                l++;
            }
        }
        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution sol;
    vector<int> ans = sol.twoSum(a, a[0] + a[1]);
    if (ans.size()) {
        for (int i = 0; i < 2; i++) {
            cout << ans[i] << " \n"[i == 1];
        }
    } else {
        cout << "-1\n";
    }
    return 0;
}