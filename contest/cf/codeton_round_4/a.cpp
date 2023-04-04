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
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (i >= a) flag = 1;
    }
    cout << (flag ? "YES" : "NO") << '\n';
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