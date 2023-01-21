n#include <bits/stdc++.h>

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

/*
找到一个集合使得, 任意子集和都不等于k
然后求这个集合的最大元素数
考虑(k + 1) / 2到k - 1, 任意两个元素相加都大于k

另外一种可能就是所有元素都大于k

*/

void solve() {
    int n, k;
    cin >> n >> k;
    vt<int> ans;
    for (int i = k + 1; i <= n; i++) {
        ans.pb(i);
    }
    for (int i = (k + 1) / 2; i < k; i++) { // 任意两个元素相加都大于k, 记得考虑奇数
        ans.pb(i);
    }
    print(sz(ans));
    print(ans);
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