#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define len(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

bool check() {
    system("generate>in");
    ifstream fin("in");
    int tt;
    cin >> tt;
    int n;
    fin >> n;
    vector<pair<int, int>> t(n);
    for (int i=0; i<n; i++) {
        cin >> t[i].first;
    }
    for (int i=0; i<n; i++) {
        cin >> t[i].second;
    }
    fin.close();
    system("sol<in>out");
    fin.open("out");
    int m;
    fin >> m;
    if (m==-1) {
        fin.close();
        return 1;
    }
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        swap(t[l], t[r]);
    }
    for (int i=0; i<n; i++) {
        if (t[i].first!=t[n-1-i].second) {
            fin.close();
            return 0;
        }
    }
    fin.close();
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int iter=100;
    while (iter--) {
        if (check()) {
            cerr << "test passed\n";
        } else {
            cerr << "test failed\n";
            break;
        }
    }
    return 0;
}