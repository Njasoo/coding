#include <bits/stdc++.h>

using namespace std;

const int N = 200005;
int test;
pair<int, int> a[N];
int yes[N]; 
long long sum[N];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i - 1].first;
    }
    vector<int> ans = {a[n].second};
    int index = n;
    while (index > 1 && sum[index] >= a[index].first) { // 倒推 
        index--;
        ans.push_back(a[index].second);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int& x : ans) {
        cout << x << " ";
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    for (test = 1; test <= tt; test++) {
        solve();
    }
    return 0;
}