#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans, mndiff = (int)1e9;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int cnt = nums[i] + nums[l] + nums[r];
                if (cnt < target) {
                    int diff = target - cnt;
                    if (diff < mndiff) {
                        mndiff = diff;
                        ans = cnt;
                    }
                    l++;
                } else if (cnt > target) {
                    int diff = cnt - target;
                    if (diff < mndiff) {
                        mndiff = diff;
                        ans = cnt;
                    }
                    r--;
                } else {
                    ans = cnt;
                    break;
                }
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
    int ans = sol.threeSumClosest(a, a[0] + a[1] + a[2]);
    cout << ans << '\n';
    return 0;
}