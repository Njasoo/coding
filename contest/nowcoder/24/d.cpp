#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    cin >> n >> k >> x;
    priority_queue<int> q;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        q.push(a);
    }
    while (k) {
        int u = q.top();
        q.pop();
        k--;
        u -= x;
        q.push(u);
    }
    cout << q.top() << '\n';
    return 0;
}