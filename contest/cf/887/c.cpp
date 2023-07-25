#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N];
int n, k;
// O(k * log2(1e11) * log2(n))
// 但是感觉这答案不具有单调性啊, 大于答案的M有什么性质吗
// 小于倒是有单调性, 小于答案的一定被删掉了
// 但是大于的时候也有可能被删掉
// 没有被删掉的一定大于等于ans
long long check(long long M) {
    // 如何判断一个数有没有被删掉
    // 逆向模拟过程当中有一个a[mid] == M的话, 说明被删掉了
    // 找一个最大的<M的a[i]
    // 则mid前面有i个数被删掉了
    // 我好像可以通过check函数查询这个数在k轮之后的排名
    // 如果k轮之后排名等于1, 那不就是这个数吗?, 所以到这里就可以结束是吧, 妈的为什么还要继续收缩区间
    // 发现第一个测试案例的5, check函数的排名也是1
    // 所以check函数并不是真正的排名函数, 而是判断这个M排名至多为多少
    // 换句话说, check函数不考虑M被删掉的情况(这样好像就清晰多了)
    // 但是让我再写一次, 我想不出来
    for (int i = 1; i <= k; i++) {
        if (M > a[n]) {
            M -= n;
            continue;
        }
        int pos = upper_bound(a + 1, a + 1 + n, M) - a;
        if (pos == 1) return 0; // 太小了
        pos--;
        M -= pos; // 不是-=a[pos]
        // while (j >= 1 && M < a[j]) j--;
        // M -= j;
        // if (M <= 0) return 0;
    }
    return M;
}
void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {  
        cin >> a[i];
    }
    if (a[1] != 1) {
        cout << "1\n";
        return;
    }
    // 这也能二分?
    // 找一个最小的没有被删的数
    // 最大也就n * k + 1, 2 * 10 ^ 5的平方 10e11足矣
    long long l = 1, r = 1e11;
    // cerr << "check(5): " << check(5) << endl;
    long long ans = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long res = check(mid);
        if (res == 0) {
            l = mid + 1;
        } else {
            if (res == 1) {
                ans = mid;
                // break;
            }
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}