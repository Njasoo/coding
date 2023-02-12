#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " " << x << endl
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(time(0));
    cout << rng() % 1000 << " " << rng() % 1000 << '\n';
    return 0;
}