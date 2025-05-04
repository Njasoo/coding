#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << "1\n";
    int n=rng()%10+1;
    cout << n << "\n";
    vector<int> p1(n), p2(n);
    iota(all(p1), 1);
    iota(all(p2), 1);
    random_shuffle(all(p1));
    random_shuffle(all(p2));
    for (int i=0; i<n; i++) {
        cout << p1[i] << " \n"[i==n-1];
    }
    for (int i=0; i<n; i++) {
        cout << p2[i] << " \n"[i==n-1];
    }
    return 0;
}