#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int a[N];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int len = unique(a + 1, a + 1 + n) - (a + 1);
    if (k > len) {
        cout << "NO RESULT\n";
    } else {
        cout << a[k] << '\n';
    }
    return 0;
}