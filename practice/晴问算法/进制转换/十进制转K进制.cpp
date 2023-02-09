#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " = " << x << endl
char match[16];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 10; i < 16; i++) {
        match[i] = 'A' + i - 10;
    }
    vector<char> ans;
    while (n) {
        if (n % k >= 10) {
            ans.push_back(match[n % k]);
        } else {
            ans.push_back(n % k + '0');
        }
        n /= k;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i];
    }
    return 0;
}