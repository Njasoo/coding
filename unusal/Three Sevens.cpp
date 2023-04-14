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
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (int)a[i].size(); i++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
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