#include <bits/stdc++.h>

using namespace std;

// 方法1，选择其中一群怪杀死其中的一只，能量加1
// 方法2，选择其中一群怪杀死其中的x（当前能量）只，能量清零
// 问最少需要多少次将怪物杀完
// 对一个群体使用大招的话能杀死min(x, a[i])只怪

const int N = 2e5 + 5;
long long a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        int l = 1, r = n;
        while (l < r) {
            
        }
    }
    return 0;
}