#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define db(x) cerr << #x << "=" << (x) << " "
#define el cerr << "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> t(n);
    for (int i=0; i<n; i++) {
        cin >> t[i].first;
    }
    for (int i=0; i<n; i++) {
        cin >> t[i].second;
    }
    vector<pair<int, int>> t1, t2;
    for (int i=0; i<n; i++) {
        if (t[i].first>t[i].second) {
            t1.push_back(t[i]);
        } else {
            t2.push_back(t[i]);
        }
    }
    sort(t1.begin(), t1.end(), [&](auto i, auto j) {
        return i.second>j.second;
    });
    sort(t2.begin(), t2.end(), [&](auto i, auto j) {
        return i.first<j.first;
    });
    t.clear();
    for (int i=0; i<(int)t2.size(); i++) {
        t.push_back(t2[i]);
    }
    for (int i=0; i<(int)t1.size(); i++) {
        t.push_back(t1[i]);
    }
    ll pref=0, last=0;
    for (int i=0; i<n; i++) {
        pref+=t[i].first;
        last=max(last, pref)+t[i].second;
    }
    cout << last << "\n";
    return 0;
}