#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cassert>
#include <map>
#include <numeric>
#include <iomanip>
#include <set>

using namespace std;

#define db(x) cerr << (#x) << " = " << x << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a + b < c + d) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}