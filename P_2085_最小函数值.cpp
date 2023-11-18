#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const int N = 10005;
long long a[N], b[N], c[N];
long long val[1000005];

long long calc(long long A, long long B, long long C, long long x) {
    return A * x * x + B * x + C;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 100; j++) {
            val[++idx] = calc(a[i], b[i], c[i], j);
        }
    }
    sort(val + 1, val + 1 + idx);
    for (int i = 1; i <= m; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}