#include <bits/stdc++.h>
const int N = 5e4 + 5;
// 显然需要排序
// 然后二分答案，枚举每个区间的极差
// 找到了第一个陈列架要放的砖石就把它们删掉
// 二分好像在大多数情况正确，但可能出现3 + 3 > 1 + 4的情况
// 所以只能用双指针了
// 题意是要找两段满足条件长度和最大的区间
// 可能会有重叠，所以找i左边最大的区间和右边最大的区间
int a[N], b[N];
int n, k;
int cnt[N], l[N], r[N];
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + 1 + n);
    l[1] = r[n] = 1; // 易错点，初始化
    for (int i = 2, j = 1; i <= n; i++) {
        // 有点像弹簧，拉太长自己缩回来
        while (a[i] - a[j] > k) j++;
        l[i] = std::max(l[i - 1], i - j + 1);
    }
    for (int i = n - 1, j = n; i >= 1; i--) {
        while (a[j] - a[i] > k) j--;
        r[i] = std::max(r[i + 1], j - i + 1);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans = std::max(ans, l[i] + r[i + 1]);
    }
    std::cout << ans << '\n';
    return 0;
}