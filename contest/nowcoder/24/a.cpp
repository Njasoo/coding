#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        vector<int> t;
        for (int j = 0; j < n; j++) {
            t.push_back(++cur);
        }
        if (i % 2) {
            reverse(t.begin(), t.end());
        }
        for (int x : t) {
            cout << x << " ";
        }
        cout << '\n';
    }   
    return 0;
}