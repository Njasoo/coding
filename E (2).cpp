#include <bits/stdc++.h>
using namespace std;

#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl
typedef long long i64;
typedef unsigned long long u64;

// 问前缀，找到第一个ask(1, i)不等于零的地方，这里第一个不等于零的a[i]表示的是i + 1之前有多少个连续的零
// 所以i - a[i] + 1 ~ i都是0, 1 ~ i - a[i]都是1
// i + 1后面的看ask(1, j)有没有发生变化就行

const int N = 1e4 + 5;
i64 a[N];
char s[N];

i64 ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    i64 res;
    cin >> res;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i < n; i++) {
            a[i] = ask(1, i + 1);
        }
        int i = 1;
        while (i <= n && a[i] == 0) {
            i++;
        }
        if (i == n + 1) {
            cout << "! IMPOSSIBLE" << endl;
            continue;
        }
        for (int j = 1; j <= i - a[i]; j++) {
            s[j] = '1';
        }
        for (int j = i - a[i] + 1; j <= i; j++) {
            s[j] = '0';
        }
        for (int j = i + 1; j <= n; j++) {
            s[j] = (a[j] > a[j - 1] ? '1' : '0');
        }
        cout << "! ";
        for (int j = 1; j <= n; j++) {
            cout << s[j];
        }
        cout << '\n';
    }   
    return 0;
}