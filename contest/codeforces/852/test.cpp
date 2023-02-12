#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(time(0));
    int n = rng() % 10 + 1;
    cout << n << '\n';
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    random_shuffle(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}