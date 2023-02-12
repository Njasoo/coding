#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<pair<int, int>> p(2);
    p[0] = {1, 2};
    p[1] = {3, 4};
    for (auto [x, y] : p) {
        cout << x << " " << y << '\n';
    }
    return 0;
}