#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

bool check(int x) {
    if (x == 1) return 0;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll sum = 0;
    for (int i = 0; i < sz(s); i++) {
        sum += s[i] - '0';
    }
    if (check(sum)) {
        cout << "OK" << "\n";
    } else {
        cout << "Failed\n";
    }
    return 0;
}