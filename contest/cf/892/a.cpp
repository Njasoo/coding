#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int c = -1;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int j = 0; j < n; j++) {
            if (i == j || a[i] == a[j]) continue;
            if (a[j] % a[i] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            c = a[i];
            break;
        }
    }
    if (c == -1) {
        cout << "-1\n";
        return;
    }
    if (min(n - cnt[c], cnt[c]) == 0) {
        cout << "-1\n";
        return;
    }
    cout << n - cnt[c] << " " << cnt[c] << '\n';
    for (int i = 0; i < n; i++) {
        if (a[i] != c) {
            cout << a[i] << " ";
        }
    }
    cout << '\n';
    for (int i = 0; i < cnt[c]; i++) {
        cout << c << " \n"[i == cnt[c] - 1];
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