#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> strs(n);
    int least = 205, mark;
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        if (strs[i].size() < least) {
            least = strs[i].size();
            mark = i;
        }
    }
    for (int i = 1; i <= least; i++) {
        string temp = strs[mark].substr(0, i);
        for (int j = 0; j < n; j++) {
            if (temp != strs[j].substr(0, i)) {
                cout << strs[0].substr(0, i - 1);
                return 0;
            }
        }
    }
    cout << strs[0] << '\n';
    return 0;
}