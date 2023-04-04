#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>
 
using namespace std;
 
#define db(x) cerr << #x << " = " << (x) <<endl
#define N 1000005
#define M 500005
#define MN 1000000
#define LOG 20
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    while (n != 1) {
        if ((n + 1) / 2 % 2) {
            n++;
            ans.push_back(1);
        } else {
            n--;
            ans.push_back(2);
        }
        n >>= 1;
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " \n"[i == 0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}