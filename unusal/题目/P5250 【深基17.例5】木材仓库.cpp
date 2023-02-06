#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> ds;
    while (n--) {
        int opt, len;
        cin >> opt >> len;
        if (opt == 1) {
            auto it = ds.find(len);
            if (it != ds.end()) {
                cout << "Already Exist" << '\n';
            } else {
                ds.insert(len);
            }
        } else if (ds.empty()) {
            cout << "Empty" << '\n';
        } else {
            auto it = lower_bound(ds.begin(), ds.end(), len);
            set<int>::iterator j = it;
            if (j != ds.begin()) {
                j--;
            }
            if (it != ds.end() && abs(len - *j) > abs(len - *it)) {
                j = it;
            }
            cout << *j << '\n';
            ds.erase(j);
        }
    }   
    return 0;
}