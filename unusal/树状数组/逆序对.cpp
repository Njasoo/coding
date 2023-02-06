#include <bits/stdc++.h>

using namespace std;

long long n, t[500005];

struct node {
    long long val, num;
}a[500005];

void add(int x) {
    while (x <= n) {
        t[x]++;
        x += x & -x;
    }
}

long long sum(int x) {
    long long ans = 0;
    while (x) {
        ans += t[x];
        x -= x & -x;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].num = i;
    }
    sort(a + 1, a + 1 + n, [](node i, node j) {
        if (i.val == j.val) {
            return i.num > j.num;
        }
        return i.val > j.val;
    });
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        add(a[i].num);
        ans += sum(a[i].num - 1);
    }
    cout << ans << '\n';
    return 0;
}