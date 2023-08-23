#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl

// 反过来就类似辗转相除法

int cnt_gcd(int a, int b) {
    if (b > a) swap(a, b);
    int r = a % b;
    int res = a / b;
    while (r) {
        a = b;
        b = r;
        r = a % b;
        res += a / b;
    }
    if (b == 1) return res - 1; // 不要变成零, 而是变成1, 所以补上
    return (int) 1e9;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 1e9;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, cnt_gcd(n, i));
    }
    cout << ans << '\n';
    return 0;
}