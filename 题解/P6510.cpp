#include <bits/stdc++.h>
using namespace std;
// 枚举B, 然后找从B开始往左数第一个大于等于B的位置k1, 那么A应该在(k1, i - 1]这个范围里面
// 同时A要满足在(k1, i - 1]这个区间内最小, 所以可以搞一个存B前面最小值的单调栈, 然后找最靠左的那一个位置
const int N = 1e5 + 5;
int a[N], st1[N], st2[N]; // st1: < B, st2: >= B[i]
int top1, top2;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int B = a[i];
        while (top1 && a[st1[top1]] >= B) top1--;
        while (top2 && a[st2[top2]] < B) top2--;
        int pos = -1;
        int l = 1, r = top1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (st1[mid] > st2[top2]) {
                r = mid - 1;
                pos = mid;
            } else {
                l = mid + 1;
            }
        }
        if (pos != -1) {
            ans = max(ans, i - st1[pos] + 1);
        }
        st1[++top1] = i;
        st2[++top2] = i;
    }
    cout << ans << '\n';
    return 0;
}