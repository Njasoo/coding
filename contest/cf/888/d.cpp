#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << " = " << (x) << endl
const int N = 2e5 + 5;
long long sum[N];
void solve() {
    int n;
    cin >> n;
    bool flag = 0;
    for (int i = 1; i < n; i++) {
        cin >> sum[i];
        if (sum[i] == 1LL * n * (n + 1) / 2) {
            flag = 1;
        }
    }
    set<long long> s;
    if (!flag) { // 遗失的是最后一项
        sum[n] = 1LL * n * (n + 1) / 2;
        for (int i = 1; i <= n; i++) {
            long long cnt = sum[i] - sum[i - 1];
            if (cnt > n) continue;
            s.insert(cnt);
        }
        if (s.size() == n) {
            cout << "YES\n";
        } else {
            cerr << "NO1" << endl;
            cout << "NO\n";
        }
        return;
    }
    // flag = 0;
    // 遗失的可能是第一项
    for (int i = 1; i < n; i++) {
        long long cnt = sum[i] - sum[i - 1];
        if (cnt > n) continue;
        // db(cnt);
        s.insert(cnt);
    }
    for (int i = 1; i <= n; i++) {
        auto it1 = s.find(i);
        auto it2 = s.find(sum[1] - i);
        if (it1 == s.end() && it2 == s.end()) {
            s.insert(i);
            s.insert(sum[1] - i);
            break;
        }
    }
    if (s.size() == n) {
        cout << "YES\n";
        return;
    }
    // 遗失的是中间的某一项
    // 那么最多应该也就是缺两项
    // sum[i] - sum[i - 1], sum[i + 1] - sum[i]这两项不见了
    // a[i] 和 a[i + 1]
    // sum[i - 1] + a[i] + a[i + 1] = sum[i + 1]
    s.clear();
    int pos = -1;
    for (int i = 1; i < n; i++) {
        long long cnt = sum[i] - sum[i - 1];
        if (cnt > n) {
            pos = i;
            continue;
        }
        s.insert(cnt);
    }
    // db(s.size());
    if (pos != -1) {
        if (s.size() != n - 2) {
            cerr << "NO2" << endl;
            cout << "NO\n";
            return;
        }
        pair<long long, long long> temp;
        for (int i = 1; i <= n; i++) {
            auto it = s.find(i);
            if (it == s.end()) {
                temp.first = i;
                s.insert(i);
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            auto it = s.find(i);
            if (it == s.end()) {
                temp.second = i;
                // cerr << "i: " << i << endl;
                s.insert(i);
                break;
            }
        }
        if (sum[pos - 1] + temp.first + temp.second == sum[pos]) {
            cout << "YES\n";
        } else {
            cerr << "NO3" << endl;
            cout << "NO\n";
        }
        return;
    }
    vector<int> poss;
    map<long long, bool> hs;
    long long rp = 0;
    for (int i = 1; i < n; i++) {
        long long cnt = sum[i] - sum[i - 1];
        if (hs[cnt] == 1) {
            rp = cnt;
            break;
        }
        hs[cnt] = 1;
    }
    for (int i = 1; i < n; i++) {
        long long cnt = sum[i] - sum[i - 1];
        if (cnt == rp) {
            poss.push_back(i);
        }
    }
    pair<int, int> temp;
    for (int i = 1; i <= n; i++) {
        auto it = s.find(i);
        if (it == s.end()) {
            temp.first = i;
            s.insert(i);
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        auto it = s.find(i);
        if (it == s.end()) {
            temp.second = i;
            s.insert(i);
            break;
        }
    }
    if (s.size() != n) {
        cerr << "NO4" << endl;
        cout << "NO\n";
        return;
    }
    assert(poss.size() == 2);
    if (sum[poss[0] - 1] + temp.first + temp.second == sum[poss[0]] || sum[poss[1] - 1] + temp.first + temp.second == sum[poss[1]]) {
        cout << "YES\n";
    } else {
        cerr << "NO5" << endl;
        cout << "NO\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}