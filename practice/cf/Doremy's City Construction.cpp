#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
const int N = 2e5 + 5;
int a[N], t[N];
int n;
void add(int x, int k) {
    while (x <= n) {
        t[x] += k;
        x += x & -x;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
    }
    return 0;
}