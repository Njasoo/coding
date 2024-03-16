#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define db(x) cerr << #x << " = " << (x) << " "
#define el cerr << endl

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int i = 0;
    while (i < s.size() && s[i] == '0') {
        i++;
    }   
    if (i == s.size()) {
        cout << "0\n";
        return 0;
    }
    int j = i + 1;
    vector<int> pref(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
        pref[i + 1] = pref[i];
        if (s[i] == '1') {
            pref[i + 1]++;
        } else {
            pref[i + 1]--;
        }
    }
    int ans = 1;
    while (j < s.size()) {
        ans = max(ans, pref[s.size()] - pref[j] + 1);
        j++;
    }
    cout << ans << '\n';
    return 0;
}