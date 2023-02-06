#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define vt vector
#define sz(x) (int) (x).size()
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second

template <typename T>
void print(T ans_for_output) {
    cout << ans_for_output << '\n';
}

template <typename T>
void print(vector<T> anss_for_output) {
    for (int i = 0; i < sz(anss_for_output); i++) {
        cout << anss_for_output[i] << " \n"[i == sz(anss_for_output) - 1];
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> a(n);
    const int inf = 1e9;
    int max_low = 0, min_high = inf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        max_low = max(max_low, a[i] - k);
        min_high = min(min_high, a[i] + k);
    }
    if (max_low > min_high) {
        print(-1);
    } else {
        print(min_high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }   
    return 0;
}