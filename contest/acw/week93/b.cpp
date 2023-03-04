#include <bits/stdc++.h>
using namespace std;
int len(long long x) {
    int res = 0;
    while (x) {
        x /= 10;
        res++;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long x;
    cin >> n >> x;
    queue<tuple<long long, int, int>> q; // (val, len, step)
    q.push({x, len(x), 0});
    unordered_set<long long> s;
    s.insert(x);
    while (!q.empty()) {
        auto [val, y, z] = q.front();
        q.pop();
        if (y == n) {
            cout << z << '\n';
            return 0;
        }
        long long temp = val;
        while (temp != 0) {
            long long num = val * (temp % 10);
            if (num <= val) {
                temp /= 10;
                continue;
            } else if (s.find(num) != s.end()) {
                temp /= 10;
                continue;
            }
            q.push({num, len(num), z + 1});
            s.insert(num);
            temp /= 10;
        }
    }
    cout << "-1\n";
    return 0;
}