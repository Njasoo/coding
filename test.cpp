#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = "<< (x) <<endl
#define sz(x) (int)(x).size()
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a = {-3, -2, -1, 0, 1, 2, 3, 4};
    vector<int> b = {-1, -1, -1, -1, -1, -1, -1, 4};
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        ans += abs(a[i] - b[i]);
    }   
    cout << ans << '\n';
    return 0;
}