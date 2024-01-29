#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cassert>
#include <map>

using namespace std;

#define db(x) cerr << (#x) << " = " << x << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int pre;
    cin >> pre;
    bool flag = true;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        if (a != pre + 1) {
            flag = false;
        }
        pre = a;
    }
    cout << (flag ? "YES" : "NO") << '\n';
    return 0;
}