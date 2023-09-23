#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int d;
            cin >> d;
            if (i == j) continue;
            if (d != 2 && d != 0) {
                deg[i]++;
            }
        }
    }   
    // for (int i = 0; i < n; i++) {
    //     cout << deg[i] << " \n"[i == n - 1];
    // }
    int ans = 0;
    vector<int> real_ans;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            real_ans.push_back(i);
        }
    }
    cout << real_ans.size() << '\n';
    for (int i = 0; i < real_ans.size(); i++) {
        cout << real_ans[i] + 1 << " \n"[i == real_ans.size() - 1];
    }
    return 0;
}