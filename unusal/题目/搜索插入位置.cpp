#include <bits/stdc++.h>

using namespace std;

// 如果没有找到值
// 左指针会指向最小的大于k的值
// 右指针会指向最大的小于k的值

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
        int mid = l + (r - l) / 2;
        if (a[mid] == k) {
            cout << mid << '\n';
            return 0;
        } else if (a[mid] < k) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r + 1 << '\n';
    return 0;
}