#include <bits/stdc++.h>

using namespace std;

// 把一个数组对半分开，必然其中一个数组有序
// 然后检查target是否在有序数组的范围内，在就按照二分查找来做
// 不在就搜索另外一半

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] == k) {
            cout << mid << '\n';
            return 0;
        } else if (a[mid] < a[r]) {
            if (a[mid] <= k && k <= a[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        } else {
            if (a[l] <= k && k <= a[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << -1 << '\n';
    return 0;
}