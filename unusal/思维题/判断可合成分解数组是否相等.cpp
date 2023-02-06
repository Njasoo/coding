#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<array<long long, 2>> new_a, new_b;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            int number = 1;
            while (a % m == 0) {
                a /= m;
                number *= m;
            }
            if (!new_a.empty() && new_a.back()[0] == a) {
                new_a.back()[1] += number;
            } else {
                new_a.push_back({a, number});
            }
        }
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int b;
            cin >> b;
            int number = 1;
            while (b % m == 0) {
                b /= m;
                number *= m;
            }
            if (!new_b.empty() && new_b.back()[0] == b) {
                new_b.back()[1] += number;
            } else {
                new_b.push_back({b, number});
            }
        }
        cout << (new_a == new_b ? "Yes" : "No") << '\n';
    }      
    return 0;
}